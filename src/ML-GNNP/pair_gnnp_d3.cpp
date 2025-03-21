/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_gnnp_d3.h"

using namespace LAMMPS_NS;

PairGNNPD3::PairGNNPD3(LAMMPS *lmp) : PairGNNP(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairGNNPD3::~PairGNNPD3()
{
    // NOP
}

int PairGNNPD3::withDFTD3()
{
    return 1;
}

int PairGNNPD3::withGPU()
{
    return 0;
}

