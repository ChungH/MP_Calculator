//
//  Instructor.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#ifndef __processor_calculator__Instructor__
#define __processor_calculator__Instructor__

#include <iostream>
#include <sstream>
#include "Operate.h"
#include "FileIO.h"

#define NumberOfOper 5

enum OperateCode {
    ERROR=-1,
    SUM,
    SUB,
    MUL,
    DIV,
    MOD,
    MOVE,
    MOVER
};

class Instructor{

private:
    char    _operator;
    int     _opCode;
    int     _regNumber1;
    int     _regNumber2;
    int     _operand1;
    int     _operand2;
    int (*operatorPtr[NumberOfOper])(int ,int)={
        Operate::Sum,
        Operate::Sub,
        Operate::Mul,
        Operate::Div,
        Operate::Mod
    };
    
    
public:
    Instructor();
//    ~Instructor();

private:
    void    InterpretOpCode(char* inst_reg);
    void    InterpretOperand(char* inst_reg);
    void    Calculate(int* reg_var);
    void    GetOperand(char** inst_reg,char* operand);
    void    SaveResult(int* reg_var,FileIO* fileManager);
    
public:
    bool    ExcuteInstruction(char* inst_reg,int* reg_var,
                              FileIO* fileManager);
    
};

#endif /* defined(__processor_calculator__Instructor__) */







