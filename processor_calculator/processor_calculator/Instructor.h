//
//  Instructor.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once

#include <iostream>
#include <sstream>
#include <array>
#include "Common.h"
#include "Instruction.h"

#define MAX_MEMORY 8192

class Instructor {
public:
    static std::array<unsigned int, 8192>  _memory;
    static std::array<unsigned int, 32>    _register;
    
private:
    unsigned int                    _pc;
    unsigned int&                   _gp = _register[28];
    unsigned int&                   _sp = _register[29];
    unsigned int&                   _fp = _register[30];
    unsigned int&                   _ra = _register[31];
    
public:
    Instructor();
    
private:
    void                    LoadInstruction();
    unsigned int            Fetch();
    Instruction*            Decode(unsigned int const inst);
    bool                    Excute(Instruction* inst);
    
    unsigned int            GetExtension(unsigned int sign, unsigned int immediate);
public:
    void                    ExcuteInstruction();
    
    void                    SetDataToMemory(int index, unsigned int val);
    unsigned int            GetDataFromMemory(int index);
    
    GET_SET_FUNCT(unsigned int, ProgramCounter, _pc);
    GET_SET_FUNCT(unsigned int, StackPointer, _sp);
    GET_SET_FUNCT(unsigned int, ReturnAddress, _ra);

};
