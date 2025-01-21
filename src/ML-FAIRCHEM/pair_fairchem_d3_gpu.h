/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#ifdef PAIR_CLASS

PairStyle(fairchem/d3/gpu, PairFAIRChemD3GPU)

#else

#ifndef LMP_PAIR_FAIRCHEM_D3_GPU_H_
#define LMP_PAIR_FAIRCHEM_D3_GPU_H_

#include "pair_fairchem.h"

namespace LAMMPS_NS
{

class PairFAIRChemD3GPU: public PairFAIRChem
{
public:
    PairFAIRChemD3GPU(class LAMMPS*);

    virtual ~PairFAIRChemD3GPU() override;

protected:
    int withDFTD3() override;

    int withGPU() override;
};

}  // namespace LAMMPS_NS

#endif /* LMP_PAIR_FAIRCHEM_D3_GPU_H_ */
#endif
