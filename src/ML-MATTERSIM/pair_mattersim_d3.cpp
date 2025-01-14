/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_mattersim_d3.h"

using namespace LAMMPS_NS;

PairMatterSimD3::PairMatterSimD3(LAMMPS *lmp) : PairMatterSim(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairMatterSimD3::~PairMatterSimD3()
{
    // NOP
}

int PairMatterSimD3::withDFTD3()
{
    return 1;
}

int PairMatterSimD3::withGPU()
{
    return 0;
}

