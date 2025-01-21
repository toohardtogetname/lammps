/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_fairchem_d3.h"

using namespace LAMMPS_NS;

PairFAIRChemD3::PairFAIRChemD3(LAMMPS *lmp) : PairFAIRChem(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairFAIRChemD3::~PairFAIRChemD3()
{
    // NOP
}

int PairFAIRChemD3::withDFTD3()
{
    return 1;
}

int PairFAIRChemD3::withGPU()
{
    return 0;
}

