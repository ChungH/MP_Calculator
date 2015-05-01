//
//  Subtract.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class Subtract : public R_Instruction {
public:
    Subtract(unsigned int rs, unsigned int rt, unsigned int rd);
public:
    virtual bool Execution();
};


class SubtractUnsigned : public R_Instruction {
public:
    SubtractUnsigned(unsigned int rs, unsigned int rt, unsigned int rd);
public:
    virtual bool Execution();
};


