//
//  Instruction.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once

class Instruction{
public:
    virtual bool Excution() = 0;
};


class R_Instruction : public Instruction{
public:
    unsigned int    _opcode;
    unsigned int    _rs;
    unsigned int    _rd;
    unsigned int    _shamt;
    unsigned int    _funct;
    
public:
    R_Instruction(unsigned int opcode, unsigned int rs, unsigned int rd,unsigned int shamt, unsigned int funct);
public:
    virtual bool Excution() = 0;
    
};

class I_Instruction : public Instruction{
public:
    unsigned int    _opcode;
    unsigned int    _rs;
    unsigned int    _rt;
    unsigned int    _immediate;
    
public:
    I_Instruction(unsigned int opcode, unsigned int rs, unsigned int rt,unsigned int immediate);
    
public:
    virtual bool Excution() = 0;
    
};

class J_Instruction : public Instruction{
public:
    unsigned int    _opcode;
    unsigned int    _address;
    
public:
    J_Instruction(unsigned int opcode, unsigned int address);
    
public:
    virtual bool Excution() = 0;
    
};
