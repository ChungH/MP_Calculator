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

#define MAX_MEMORY 16384

class Instructor {
public:
    static std::array<unsigned int, MAX_MEMORY>  _memory;
    static std::array<unsigned int, 32>    _register;
    static unsigned int                    _pc;
    static unsigned int                    _hi;
    static unsigned int                    _lo;
    static std::string                     _logBuffer;
    static int                             _lastBranch;
    static int hit;
    static int miss;
    
private:
    unsigned int&                          _gp = Instructor::_register[28];
    unsigned int&                          _sp = Instructor::_register[29];
    unsigned int&                          _fp = Instructor::_register[30];
    unsigned int&                          _ra = Instructor::_register[31];
    
public:
    Instructor(const char* filePath);
    
private:
    const char*             _filePath;
    
public:
    Instruction*            _EXEInst;
    Instruction*            _MEMInst;
    Instruction*            _WBInst;
    Instruction*            _DECInst;
    unsigned int            _fetchInst;
    
    
private:
    bool                    _MEM_rs;
    bool                    _MEM_rt;
    bool                    _WB_rs;
    bool                    _WB_rt;
   
    bool                    _branchChk;
    bool                    _jumpChk;


    
    
private:
    void                    LoadInstruction();
    unsigned int            Fetch();
    Instruction*            Decode(unsigned int const inst);
    
    unsigned int            GetExtension(unsigned int sign, unsigned int immediate);
    
    void                    DataForwarding();
    void                    DependencyChk();
    void                    DecodeInstName(unsigned int inst);
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
