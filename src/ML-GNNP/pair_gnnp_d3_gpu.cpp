/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#include "pair_gnnp_d3_gpu.h"

using namespace LAMMPS_NS;

PairGNNPD3GPU::PairGNNPD3GPU(LAMMPS *lmp) : PairGNNP(lmp)
{
    if (copymode)
    {
        return;
    }

    // NOP
}

PairGNNPD3GPU::~PairGNNPD3GPU()
{
    // NOP
}

int PairGNNPD3GPU::withDFTD3()
{
    return 1;
}

int PairGNNPD3GPU::withGPU()
{
    return 1;
}

