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
    int _hi;
    int _lo;
public:
    Divide(unsigned int rs, unsigned int rt,unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};


class DivideUnsigned : public R_Instruction {
public:
    unsigned int _hi;
    unsigned int _lo;
public:
    DivideUnsigned(unsigned int rs, unsigned int rt, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};