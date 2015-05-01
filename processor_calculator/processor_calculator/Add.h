//
//  Add.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class Add : public R_Instruction {
public:
    Add(unsigned int rs, unsigned int rt, unsigned int rd);
    
public:
    virtual bool Execution();
};

class AddUnsigned : public R_Instruction {
public:
    AddUnsigned(unsigned int rs, unsigned int rt, unsigned int rd);
public:
    virtual bool Execution();
};

class AddImmediate : public I_Instruction {
public:
    AddImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm);
public:
    virtual bool Execution();
};

class AddImmediateUnsigned : public I_Instruction {
public:
    AddImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm);
public:
    virtual bool Execution();
};
