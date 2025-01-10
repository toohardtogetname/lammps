/*
 * Copyright (C) 2025 AdvanceSoft Corporation
 *
 * This source code is licensed under the GNU General Public License Version 2
 * found in the LICENSE file in the root directory of this source tree.
 */

#ifdef PAIR_CLASS

PairStyle(eqv2, PairEQV2)

#else

#ifndef LMP_PAIR_EQV2_H_
#define LMP_PAIR_EQV2_H_

#include <Python.h>
#include <cstdlib>
#include "atom.h"
#include "comm.h"
#include "error.h"
#include "pair.h"
#include "force.h"
#include "update.h"
#include "memory.h"
#include "neigh_list.h"
#include "neigh_request.h"
#include "neighbor.h"
#include "domain.h"

namespace LAMMPS_NS
{

class PairEQV2: public Pair
{
public:
    PairEQV2(class LAMMPS*);

    virtual ~PairEQV2() override;

    void compute(int, int) override;

    void settings(int, char **) override;

    void coeff(int, char **) override;

    double init_one(int, int) override;

    void init_style() override;

protected:
    virtual int withDFTD3();

    virtual int withGPU();

private:
    int*      atomNumMap;
    int*      atomNums;
    double**  cell;
    double**  positions;
    double**  forces;

    int       maxinum;
    int       initializedPython;
    int       virialWarning;
    double    cutoff;

    int       npythonPath;
    char**    pythonPaths;

    PyObject* pyModule;
    PyObject* pyFunc;

    void allocate();

    void prepareGNN();

    void performGNN();

    void finalizePython();

    double initializePython(const char *name, int dftd3, int gpu);

    double calculatePython();

    int elementToAtomNum(const char *elem);

    void toRealElement(char *elem);

    static int  finalized;
    static void finalize();
};

}  // namespace LAMMPS_NS

#endif /* LMP_PAIR_EQV2_H_ */
#endif
