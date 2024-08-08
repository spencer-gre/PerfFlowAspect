/************************************************************\
 * Copyright 2021 Lawrence Livermore National Security, LLC
 * (c.f. AUTHORS, NOTICE.LLNS, COPYING)
 *
 * This file is part of the Flux resource manager framework.
 * For details, see https://github.com/flux-framework.
 *
 * SPDX-License-Identifier: LGPL-3.0
\************************************************************/

#ifndef PERFFLOW_WEAVE_ADIAK_H
#define PERFFLOW_WEAVE_ADIAK_H

#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"

#include <string>

using namespace llvm;

namespace {

class AdiakPass : public ModulePass
{
public:
    static char ID;
    AdiakPass () : ModulePass (ID) {}
    virtual bool runOnModule (Module &M);
	bool skipModule(Module &M) const;

private:

};

}

#endif // PERFFLOW_WEAVE_H


/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
