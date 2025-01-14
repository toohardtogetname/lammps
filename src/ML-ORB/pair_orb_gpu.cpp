/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_orb_gpu.h"

using namespace LAMMPS_NS;

PairORBGPU::PairORBGPU(LAMMPS *lmp) : PairORB(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairORBGPU::~PairORBGPU()
{
    // NOP
}

int PairORBGPU::withGPU()
{
    return 1;
}

