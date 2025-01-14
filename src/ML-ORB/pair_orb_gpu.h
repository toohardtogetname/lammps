/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#ifdef PAIR_CLASS

PairStyle(orb/gpu, PairORBGPU)

#else

#ifndef LMP_PAIR_ORB_GPU_H_
#define LMP_PAIR_ORB_GPU_H_

#include "pair_orb.h"

namespace LAMMPS_NS
{

class PairORBGPU: public PairORB
{
public:
    PairORBGPU(class LAMMPS*);

    virtual ~PairORBGPU() override;

protected:
    int withGPU() override;
};

}  // namespace LAMMPS_NS

#endif /* LMP_PAIR_ORB_GPU_H_ */
#endif
