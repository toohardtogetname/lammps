/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_mattersim_d3_gpu.h"

using namespace LAMMPS_NS;

PairMatterSimD3GPU::PairMatterSimD3GPU(LAMMPS *lmp) : PairMatterSim(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairMatterSimD3GPU::~PairMatterSimD3GPU()
{
    // NOP
}

int PairMatterSimD3GPU::withDFTD3()
{
    return 1;
}

int PairMatterSimD3GPU::withGPU()
{
    return 1;
}

