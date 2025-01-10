/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#ifdef PAIR_CLASS

PairStyle(eqv2/gpu, PairEQV2GPU)

#else

#ifndef LMP_PAIR_EQV2_GPU_H_
#define LMP_PAIR_EQV2_GPU_H_

#include "pair_eqv2.h"

namespace LAMMPS_NS
{

class PairEQV2GPU: public PairEQV2
{
public:
    PairEQV2GPU(class LAMMPS*);

    virtual ~PairEQV2GPU() override;

protected:
    int withDFTD3() override;

    int withGPU() override;
};

}  // namespace LAMMPS_NS

#endif /* LMP_PAIR_EQV2_GPU_H_ */
#endif
