/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_mace_d3.h"

using namespace LAMMPS_NS;

PairMACED3::PairMACED3(LAMMPS *lmp) : PairMACE(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairMACED3::~PairMACED3()
{
    // NOP
}

int PairMACED3::withDFTD3()
{
    return 1;
}

int PairMACED3::withGPU()
{
    return 0;
}

