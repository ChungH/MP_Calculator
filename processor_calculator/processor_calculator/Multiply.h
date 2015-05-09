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
    long long _resultData;
public:
    Multiply(unsigned int rs, unsigned int rt, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};


class MultiplyUnsigned : public R_Instruction {
public:
    unsigned long long _resultData;
public:
    MultiplyUnsigned(unsigned int rs, unsigned int rt, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

class Multiply32Bit : public R_Instruction {
public:
    Multiply32Bit(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};