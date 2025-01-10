/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_eqv2_d3_gpu.h"

using namespace LAMMPS_NS;

PairEQV2D3GPU::PairEQV2D3GPU(LAMMPS *lmp) : PairEQV2(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairEQV2D3GPU::~PairEQV2D3GPU()
{
    // NOP
}

int PairEQV2D3GPU::withDFTD3()
{
    return 1;
}

int PairEQV2D3GPU::withGPU()
{
    return 1;
}

