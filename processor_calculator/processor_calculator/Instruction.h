//
//  Instruction.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include "InstructionSet.h"

class Instruction{
public:
    int         _instType;
    
public:
    Instruction(int instType);
    virtual bool Execution() = 0;
    virtual void MemoryAccess() = 0;
    virtual void WriteBack() = 0;
    virtual unsigned int getRsNum() = 0;
    virtual unsigned int getRtNum() = 0;
    virtual unsigned int getRdNum() = 0;
    
};


class R_Instruction : public Instruction{
public:
    unsigned int    _rs;
    unsigned int    _rt;
    unsigned int    _rd;
    unsigned int    _shamt;
    unsigned int    _funct;
    unsigned int    _rsData;
    unsigned int    _rtData;
    unsigned int    _rdData;
    
public:
    R_Instruction(unsigned int rs, unsigned int  rt, unsigned int rd, unsigned int shamt, unsigned int funct, unsigned int rsData, unsigned int rtData);
public:
    virtual bool Execution() = 0;
    virtual void MemoryAccess() = 0;
    virtual void WriteBack() = 0;
    virtual unsigned int getRsNum() = 0;
    virtual unsigned int getRtNum() = 0;
    virtual unsigned int getRdNum() = 0;
    
};

class I_Instruction : public Instruction{
public:
    
    unsigned int    _rs;
    unsigned int    _rt;
    unsigned int    _rsData;
    unsigned int    _rtData;
    unsigned int    _immediate;
    
public:
    I_Instruction(unsigned int rs, unsigned int rt,unsigned int immediate, unsigned int rsData, unsigned int rtData);
    
public:
    virtual bool Execution() = 0;
    virtual void MemoryAccess() = 0;
    virtual void WriteBack() = 0;
    virtual unsigned int getRsNum() = 0;
    virtual unsigned int getRtNum() = 0;
    virtual unsigned int getRdNum() = 0;
};

class J_Instruction : public Instruction{
public:
    unsigned int    _address;
    
public:
    J_Instruction(unsigned int address);
    
public:
    virtual bool Execution() = 0;
    virtual void MemoryAccess() = 0;
    virtual void WriteBack() = 0;
    virtual unsigned int getRsNum() = 0;
    virtual unsigned int getRtNum() = 0;
    virtual unsigned int getRdNum() = 0;
};

