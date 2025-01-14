"""
Copyright (c) 2025, AdvanceSoft Corp.

This source code is licensed under the GNU General Public License Version 2
found in the LICENSE file in the root directory of this source tree.
"""

from ase import Atoms

from orb_models.forcefield import pretrained
from orb_models.forcefield.calculator import ORBCalculator

import torch

def orb_initialize(model_name, gpu = True):
    """
    Initialize GNNP of ORB.
    Args:
        model_name (str): name of model for GNNP.
        gpu (bool): using GPU, if possible.
    Returns:
        cutoff: cutoff radius.
    """

    # Check gpu
    device = "cuda" if (gpu and torch.cuda.is_available()) else "cpu"

    # Create CHGNetCalculator, that is pre-trained
    global myCalculator

    orbff = pretrained.ORB_PRETRAINED_MODELS[model_name](device=device)

    myCalculator = ORBCalculator(orbff, device=device)

    # Atoms object of ASE, that is empty here
    global myAtoms

    myAtoms = None

    return float(orbff.model.gnn_stacks[0]._r_max)

def orb_get_energy_forces_stress(cell, atomic_numbers, positions):
    """
    Predict total energy, atomic forces and stress w/ pre-trained GNNP of ORB.
    Args:
        cell: lattice vectors in angstroms.
        atomic_numbers: atomic numbers for all atoms.
        positions: xyz coordinates for all atoms in angstroms.
    Returns:
        energy:  total energy.
        forcces: atomic forces.
        stress:  stress tensor (Voigt order).
    """

    # Initialize Atoms
    global myAtoms
    global myCalculator

    if myAtoms is not None and len(myAtoms.numbers) != len(atomic_numbers):
        myAtoms = None

    if myAtoms is None:
        myAtoms = Atoms(
            numbers   = atomic_numbers,
            positions = positions,
            cell      = cell,
            pbc       = [True, True, True]
        )

        myAtoms.calc = myCalculator

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

