//
//  Multy.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class Multiply : public R_Instruction {
public:
    Multiply(unsigned int rs, unsigned int rt);
public:
    virtual bool Execution();
};


class MultiplyUnsigned : public R_Instruction {
public:
    MultiplyUnsigned(unsigned int rs, unsigned int rt);
public:
    virtual bool Execution();
};

class Multiply32Bit : public R_Instruction {
public:
    Multiply32Bit(unsigned int rs, unsigned int rt, unsigned int rd);
public:
    virtual bool Execution();
};