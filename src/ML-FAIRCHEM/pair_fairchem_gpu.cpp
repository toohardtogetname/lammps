/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_fairchem_gpu.h"

using namespace LAMMPS_NS;

PairFAIRChemGPU::PairFAIRChemGPU(LAMMPS *lmp) : PairFAIRChem(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairFAIRChemGPU::~PairFAIRChemGPU()
{
    // NOP
}

int PairFAIRChemGPU::withDFTD3()
{
    return 0;
}

int PairFAIRChemGPU::withGPU()
{
    return 1;
}

