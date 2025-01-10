/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_eqv2_d3.h"

using namespace LAMMPS_NS;

PairEQV2D3::PairEQV2D3(LAMMPS *lmp) : PairEQV2(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairEQV2D3::~PairEQV2D3()
{
    // NOP
}

int PairEQV2D3::withDFTD3()
{
    return 1;
}

int PairEQV2D3::withGPU()
{
    return 0;
}

