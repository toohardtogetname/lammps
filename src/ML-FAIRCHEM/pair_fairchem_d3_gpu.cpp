/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_fairchem_d3_gpu.h"

using namespace LAMMPS_NS;

PairFAIRChemD3GPU::PairFAIRChemD3GPU(LAMMPS *lmp) : PairFAIRChem(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairFAIRChemD3GPU::~PairFAIRChemD3GPU()
{
    // NOP
}

int PairFAIRChemD3GPU::withDFTD3()
{
    return 1;
}

int PairFAIRChemD3GPU::withGPU()
{
    return 1;
}

