/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#ifdef PAIR_CLASS

PairStyle(mace/gpu, PairMACEGPU)

#else

#ifndef LMP_PAIR_MACE_GPU_H_
#define LMP_PAIR_MACE_GPU_H_

#include "pair_mace.h"

namespace LAMMPS_NS
{

class PairMACEGPU: public PairMACE
{
public:
    PairMACEGPU(class LAMMPS*);

    virtual ~PairMACEGPU() override;

protected:
    int withDFTD3() override;

    int withGPU() override;
};

}  // namespace LAMMPS_NS

#endif /* LMP_PAIR_MACE_GPU_H_ */
#endif
