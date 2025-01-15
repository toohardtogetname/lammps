"""
Copyright (c) 2025, AdvanceSoft Corp.

This source code is licensed under the GNU General Public License Version 2
found in the LICENSE file in the root directory of this source tree.
"""

from ase import Atoms
from ase.calculators.mixing import SumCalculator

from mace.calculators import mace_mp

import os
import torch

def mace_initialize(model_name = None, dftd3 = False, gpu = True):
    """
    Initialize GNNP of MACE.
    Args:
        model_name (str): name of model for GNNP.
        dftd3 (bool): to add correction of DFT-D3.
        gpu (bool): using GPU, if possible.
    Returns:
        cutoff: cutoff radius.
    """

    # Check gpu
    gpu_ = (gpu and torch.cuda.is_available())

    # Create MACECalculator, that is pre-trained
    global maceCalculator

    if model_name is not None and model_name.startswith("mace-osaka24"):
        basePath   = os.path.dirname(os.path.abspath(__file__))
        model_dir  = os.path.normpath(os.path.join(basePath, "mace-osaka24_models"))
        model_path = os.path.normpath(os.path.join(model_dir, model_name))
        if not model_path.endswith(".model"):
            model_path += ".model"

        maceCalculator = mace_mp(
            model      = model_path,
            dispersion = dftd3,
            device     = ("cuda" if gpu_ else "cpu")
        )

    else:
        maceCalculator = mace_mp(
            model      = model_name,
            dispersion = dftd3,
            device     = ("cuda" if gpu_ else "cpu")
        )

    # Atoms object of ASE, that is empty here
    global myAtoms

    myAtoms = None

    if isinstance(maceCalculator, SumCalculator):
        return maceCalculator.mixer.calcs[0].r_max
    else:
        return maceCalculator.r_max

def mace_get_energy_forces_stress(cell, atomic_numbers, positions):
    """
    Predict total energy, atomic forces and stress w/ pre-trained GNNP of MACE.
    Args:
        cell: lattice vectors in angstroms.
        atomic_numbers: atomic numbers for all atoms.
        positions: xyz coordinates for all atoms in angstroms.
    Returns:
        energy:  total energy.
        forces: atomic forces.
        stress:  stress tensor (Voigt order).
    """

    # Initialize Atoms
    global myAtoms
    global maceCalculator

    if myAtoms is not None and len(myAtoms.numbers) != len(atomic_numbers):
        myAtoms = None

    if myAtoms is None:
        myAtoms = Atoms(
            numbers   = atomic_numbers,
            positions = positions,
            cell      = cell,
            pbc       = [True, True, True]
        )

        myAtoms.calc = maceCalculator

    else:
        myAtoms.set_cell(cell)
        myAtoms.set_atomic_numbers(atomic_numbers)
        myAtoms.set_positions(positions)

    # Predicting energy, forces and stress
    energy = myAtoms.get_potential_energy()
    if not isinstance(energy, float):
        energy = energy.item()
    forces = myAtoms.get_forces().tolist()
    stress = myAtoms.get_stress().tolist()

    return energy, forces, stress

