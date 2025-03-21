/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#ifdef PAIR_CLASS

PairStyle(gnnp/d3, PairGNNPD3)

#else

#ifndef LMP_PAIR_GNNP_D3_H_
#define LMP_PAIR_GNNP_D3_H_

#include "pair_gnnp.h"

namespace LAMMPS_NS
{

class PairGNNPD3: public PairGNNP
{
public:
    PairGNNPD3(class LAMMPS*);

    virtual ~PairGNNPD3() override;

protected:
    int withDFTD3() override;

    int withGPU() override;
};

}  // namespace LAMMPS_NS

#endif /* LMP_PAIR_GNNP_D3_H_ */
#endif
