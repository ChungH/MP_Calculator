//
//  SetLessThan.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once

#include "Instruction.h"

class SetLessThan : public R_Instruction {
public:
    SetLessThan(unsigned int rs, unsigned int rt, unsigned int rd);
public:
    virtual bool Execution();
};


class SetLessThanUnsigned : public R_Instruction {
public:
    SetLessThanUnsigned(unsigned int rs, unsigned int rt, unsigned int rd);
public:
    virtual bool Execution();
};


class SetLessThanImmediate : public I_Instruction {
public:
    SetLessThanImmediate(unsigned int rs, unsigned int rt, unsigned int signExtimm);
public:
    virtual bool Execution();
};


class SetLessThanImmediateUnsigned : public I_Instruction {
public:
    SetLessThanImmediateUnsigned(unsigned int rs, unsigned int rt, unsigned int immediate);
public:
    virtual bool Execution();
};

