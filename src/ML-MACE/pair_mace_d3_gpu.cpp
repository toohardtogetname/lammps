/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_mace_d3_gpu.h"

using namespace LAMMPS_NS;

PairMACED3GPU::PairMACED3GPU(LAMMPS *lmp) : PairMACE(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairMACED3GPU::~PairMACED3GPU()
{
    // NOP
}

int PairMACED3GPU::withDFTD3()
{
    return 1;
}

int PairMACED3GPU::withGPU()
{
    return 1;
}

