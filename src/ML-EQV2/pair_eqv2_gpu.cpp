/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_eqv2_gpu.h"

using namespace LAMMPS_NS;

PairEQV2GPU::PairEQV2GPU(LAMMPS *lmp) : PairEQV2(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairEQV2GPU::~PairEQV2GPU()
{
    // NOP
}

int PairEQV2GPU::withDFTD3()
{
    return 0;
}

int PairEQV2GPU::withGPU()
{
    return 1;
}

