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
#include <string.h>
#include <array>
#include "Common.h"
#include "Instruction.h"

#define MAX_MEMORY 8192

class Instructor {
public:
    static std::array<unsigned int, 8192>  _memory;
    static std::array<unsigned int, 32>    _register;
    static unsigned int                    _pc;
    static unsigned int                    _hi;
    static unsigned int                    _lo;
    static std::string                     _logBuffer;
    
private:
    unsigned int&                   _gp = Instructor::_register[28];
    unsigned int&                   _sp = Instructor::_register[29];
    unsigned int&                   _fp = Instructor::_register[30];
    unsigned int&                   _ra = Instructor::_register[31];
    
public:
    Instructor(const char* filePath);
    
private:
    const char*                    _filePath;
    
private:
    void                    LoadInstruction();
    unsigned int            Fetch();
    Instruction*            Decode(unsigned int const inst);
    bool                    Execute(Instruction* inst);
    
    unsigned int            GetExtension(unsigned int sign, unsigned int immediate);
public:
    void                    ExecuteInstruction();
    
    static void             SetDataToMemory(int index, unsigned int val);
    static unsigned int     GetDataFromMemory(int index);
    static void             SetDataToRegister(int index, unsigned int val);
    static unsigned int     GetDataFromRegister(int index);
    static void             AppendLog(const std::string& log);
    static void             PrintLog(const std::string& path);
    
//    GET_SET_FUNCT(unsigned int, ProgramCounter, _pc);
    GET_SET_FUNCT(unsigned int, StackPointer, _sp);
    GET_SET_FUNCT(unsigned int, ReturnAddress, _ra);

};
