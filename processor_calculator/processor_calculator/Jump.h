//
//  Jump.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "Instruction.h"

class Jump : public J_Instruction {
public:
    Jump(unsigned int jumpAddr);
public:
    virtual bool Excution();
};

class JumpAndLink : public J_Instruction {
public:
    JumpAndLink(unsigned int jumpAddr);
public:
    virtual bool Excution();
};

class JumpRegister : public R_Instruction {
public:
    JumpRegister(unsigned int rs);
public:
    virtual bool Excution();
};