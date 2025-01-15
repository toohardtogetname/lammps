/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_mace_gpu.h"

using namespace LAMMPS_NS;

PairMACEGPU::PairMACEGPU(LAMMPS *lmp) : PairMACE(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairMACEGPU::~PairMACEGPU()
{
    // NOP
}

int PairMACEGPU::withDFTD3()
{
    return 0;
}

int PairMACEGPU::withGPU()
{
    return 1;
}

