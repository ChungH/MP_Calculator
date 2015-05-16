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
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

class JumpAndLink : public J_Instruction {
public:
    unsigned int _pc;
public:
    JumpAndLink(unsigned int jumpAddr,unsigned int pc);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};

class JumpRegister : public R_Instruction {
public:
    JumpRegister(unsigned int rs, unsigned int rsData);
public:
    virtual bool Execution();
    virtual void MemoryAccess();
    virtual void WriteBack();
};