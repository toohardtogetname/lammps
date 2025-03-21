/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_gnnp_gpu.h"

using namespace LAMMPS_NS;

PairGNNPGPU::PairGNNPGPU(LAMMPS *lmp) : PairGNNP(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairGNNPGPU::~PairGNNPGPU()
{
    // NOP
}

int PairGNNPGPU::withDFTD3()
{
    return 0;
}

int PairGNNPGPU::withGPU()
{
    return 1;
}

