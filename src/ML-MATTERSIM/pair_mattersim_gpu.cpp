/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_mattersim_gpu.h"

using namespace LAMMPS_NS;

PairMatterSimGPU::PairMatterSimGPU(LAMMPS *lmp) : PairMatterSim(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairMatterSimGPU::~PairMatterSimGPU()
{
    // NOP
}

int PairMatterSimGPU::withDFTD3()
{
    return 0;
}

int PairMatterSimGPU::withGPU()
{
    return 1;
}

