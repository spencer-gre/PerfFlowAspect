/************************************************************\
 * Copyright 2021 Lawrence Livermore National Security, LLC
 * (c.f. AUTHORS, NOTICE.LLNS, COPYING)
 *
 * This file is part of the Flux resource manager framework.
 * For details, see https://github.com/flux-framework.
 *
 * SPDX-License-Identifier: LGPL-3.0
\************************************************************/

#include "llvm/IR/Value.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"
#ifdef PERFFLOWASPECT_CLANG_11_NEWER
#include "llvm/IR/AbstractCallSite.h"
#else
#include "llvm/IR/CallSite.h"
#endif
#include "llvm/IR/Module.h"
#include "llvm/IR/Argument.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Support/raw_ostream.h"

#include "../../parser/perfflow_parser.hpp"
#include "perfflow_weave_adiak.hpp"

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <adiak_tool.h>
#define UNUSED(x) (void)(x)

using namespace llvm;


/******************************************************************************
 *                                                                            *
 *                 Private Methods of WeavingPass Class                       *
 *                                                                            *
 ******************************************************************************/


/******************************************************************************
 *                                                                            *
 *                 Public Methods of WeavingPass Class                        *
 *                                                                            *
 ******************************************************************************/


bool AdiakPass::runOnModule(Module &m)
{

	LLVMContext &context = m.getContext();
	outs () << "In adiak module.. \n";
	// Type *int32Type = Type::getInt32Ty(getGlobalContext());
	// Type *voidType = Type::getVoidTy(getGlobalContext());
	
	// std::vector<llvm::Type *> print_params;
	// print_params.push_back(int8PtrType);
	// print_params.push_back(int32Type);
	// print_params.push_back(int8PtrType);
	// print_params.push_back(int8PtrType);
	// print_params.push_back(int8PtrType);

	// FunctionType *print_type = FunctionType::get(voidType, print_params, false);
	return true;

}

char AdiakPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerAdiakPass(const PassManagerBuilder &,
                                legacy::PassManagerBase &PM)
{
    PM.add(new AdiakPass());
}

static RegisterStandardPasses
RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
               registerAdiakPass);

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
