/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#ifdef PAIR_CLASS

PairStyle(mattersim/d3/gpu, PairMatterSimD3GPU)

#else

#ifndef LMP_PAIR_MATTERSIM_D3_GPU_H_
#define LMP_PAIR_MATTERSIM_D3_GPU_H_

#include "pair_mattersim.h"

namespace LAMMPS_NS
{

class PairMatterSimD3GPU: public PairMatterSim
{
public:
    PairMatterSimD3GPU(class LAMMPS*);

    virtual ~PairMatterSimD3GPU() override;

protected:
    int withDFTD3() override;

    int withGPU() override;
};

}  // namespace LAMMPS_NS

#endif /* LMP_PAIR_MATTERSIM_D3_GPU_H_ */
#endif
