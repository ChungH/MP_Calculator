//
//  Move.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 31..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class MoveFromHi : public R_Instruction {
public:
    MoveFromHi(unsigned int rd);
public:
    virtual bool Excution();
};


class MoveFromLo : public R_Instruction {
public:
    MoveFromLo(unsigned int rd);
public:
    virtual bool Excution();
};

class MoveToHi : public R_Instruction{
public:
    MoveToHi(unsigned int rs);
public:
    virtual bool Excution();
};

class MoveToLo : public R_Instruction{
public:
    MoveToLo(unsigned int rs);
public:
    virtual bool Excution();
};


