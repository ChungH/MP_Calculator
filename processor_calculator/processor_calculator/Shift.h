//
//  Shift.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class ShiftLeftLogical : public R_Instruction {
public:
    ShiftLeftLogical(unsigned int rt, unsigned int rd, unsigned int shamt);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};


class ShiftRightLogical : public R_Instruction {
public:
    ShiftRightLogical(unsigned int rt, unsigned int rd, unsigned int shamt);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

