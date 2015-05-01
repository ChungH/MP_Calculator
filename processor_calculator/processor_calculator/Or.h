//
//  Or.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class Nor : public R_Instruction {
public:
    Nor(unsigned int rs, unsigned int rt, unsigned int rd);
public:
    virtual bool Execution();
};

class Or : public R_Instruction {
public:
    Or(unsigned int rs, unsigned int rt, unsigned int rd);
public:
    virtual bool Execution();
};

class OrImmediate : public I_Instruction {
public:
    OrImmediate(unsigned int rs, unsigned int rt, unsigned int zeroExtimm);
public:
    virtual bool Execution();
};

