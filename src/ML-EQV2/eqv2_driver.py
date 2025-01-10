"""
Copyright (c) 2025, AdvanceSoft Corp.

This source code is licensed under the GNU General Public License Version 2
found in the LICENSE file in the root directory of this source tree.
"""

from ase import Atoms
from ase.calculators.mixing import SumCalculator

from fairchem.core.common.relaxation.ase_utils import OCPCalculator

import os
import torch

def eqv2_initialize(model_name = None, dftd3 = False, gpu = True):
    """
    Initialize GNNP of EquiformerV2.
    Args:
        model_name (str): name of model for GNNP.
        dftd3 (bool): to add correction of DFT-D3.
        gpu (bool): using GPU, if possible.
    Returns:
        cutoff: cutoff radius.
    """

    # Check gpu
    gpu_ = (gpu and torch.cuda.is_available())

    # Create Calculator
    global myCalculator

    basePath   = os.path.dirname(os.path.abspath(__file__))
    checkpt_dir = os.path.normpath(os.path.join(basePath, "eqv2_checkpt"))

    myCalculator = OCPCalculator(
        local_cache = checkpt_dir,
        model_name  = model_name,
        cpu         = not gpu_
    )

    # Add DFT-D3 to calculator without three-body term
    global eqv2Calculator
    global dftd3Calculator

    eqv2Calculator = myCalculator
    dftd3Calculator  = None

    if dftd3:
        from dftd3.ase import DFTD3
        #from torch_dftd.torch_dftd3_calculator import TorchDFTD3Calculator

        dftd3Calculator = DFTD3(
            method  = "PBE",
            damping = "d3zero",
            s9      = 0.0
        )
        #dftd3Calculator = TorchDFTD3Calculator(
        #    xc      = "pbe",
        #    damping = "zero",
        #    abc     = False
        #)

        myCalculator = SumCalculator([eqv2Calculator, dftd3Calculator])

    # Atoms object of ASE, that is empty here
    global myAtoms

    myAtoms = None

    return eqv2Calculator.config["model"].get("max_radius", 8.0)

def eqv2_get_energy_and_forces(cell, atomic_numbers, positions):
    """
    Predict total energy and atomic forces w/ pre-trained GNNP of EquiformerV2.
    Args:
        cell: lattice vectors in angstroms.
        atomic_numbers: atomic numbers for all atoms.
        positions: xyz coordinates for all atoms in angstroms.
    Returns:
        energy:  total energy.
        forces: atomic forces.
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

    return energy, forces

