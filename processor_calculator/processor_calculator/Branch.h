//
//  Branch.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class BranchOnEqual : public I_Instruction {
public:
    BranchOnEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr);
public:
    virtual bool Excution();
};

class BranchOnNotEqual : public I_Instruction {
public:
    BranchOnNotEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr);
public:
    virtual bool Excution();
};


