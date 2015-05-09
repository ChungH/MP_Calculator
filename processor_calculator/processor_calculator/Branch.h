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
    bool _branchChk;
public:
    BranchOnEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

class BranchOnNotEqual : public I_Instruction {
public:
    bool _branchChk;
public:
    BranchOnNotEqual(unsigned int rs, unsigned int rt, unsigned int branchAddr, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};


