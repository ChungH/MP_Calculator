//
//  Divide.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class Divide : public R_Instruction {
public:
    Divide(unsigned int rs, unsigned int rt);
public:
    virtual bool Excution();
};


class DivideUnsigned : public R_Instruction {
public:
    DivideUnsigned(unsigned int rs, unsigned int rt);
public:
    virtual bool Excution();
};