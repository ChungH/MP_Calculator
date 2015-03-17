//
//  Instructor.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Instructor.h"

Instructor::Instructor(){
    _opCode      = 0;
    _regNumber1  = -1;
    _regNumber2  = -1;
    _operand1    = -1;
    _operand2    = -1;
}

//Instructor::~Instructor(){
//    
//}

bool Instructor::ExcuteInstruction(char* inst_reg, int* reg_var,
                                   FileIO* fileManager){
    _opCode      = 0;
    _regNumber1  = -1;
    _regNumber2  = -1;
    _operand1    = -1;
    _operand2    = -1;
    InterpretOpCode(inst_reg);
    if(_opCode == ERROR){
        return false;
    }
    InterpretOperand(inst_reg);
    Calculate(reg_var);
    SaveResult(reg_var,fileManager);
    return true;
}


void Instructor::InterpretOpCode(char* inst_reg){
    switch (*inst_reg) {
        case '+':
            _opCode   = SUM;
            _operator = '+';
            return;
            
        case '-':
            _opCode = SUB;
            _operator = '-';
            return;
            
        case '*':
            _opCode = MUL;
            _operator = '*';
            return;
            
        case '/':
            _opCode = DIV;
            _operator = '/';
            return;
            
        case '%':
            _opCode = MOD;
            _operator = '%';
            return;
            
        case 'M':
            inst_reg+=2;
            while(*inst_reg != ' ')
                inst_reg++;
            inst_reg++;
            if(*inst_reg == 'R') {
                _opCode = MOVER;
                return;
            }
            else {
                _opCode = MOVE;
                return;
            }
            
        default:
            _opCode = ERROR;
            return;
    }
}
void Instructor::GetOperand(char** inst_reg,char* operand){
    while(**inst_reg != '\0' && **inst_reg != ' '){
        *operand= **inst_reg;
        operand++;
        (*inst_reg)+=1;
    }
    *(operand) = '\0';
}

void Instructor::InterpretOperand(char* inst_reg){
    char operand[10];
    
    //find operand1
    while (*inst_reg!= '0' && *inst_reg != 'R')
            inst_reg++;
    
    if(*inst_reg == '0') {
        inst_reg+=2;
        GetOperand(&inst_reg, operand);
//        _operand1 = atoi(operand);
        std::istringstream(operand) >> std::hex >> _operand1;
    }
    else {
        inst_reg++;
        GetOperand(&inst_reg, operand);
        _regNumber1 = atoi(operand);
    }
    
    //find operand2
    while (*inst_reg!= '0' && *inst_reg != 'R')
        inst_reg++;
    
    if(*inst_reg == '0') {
        inst_reg+=2;
        GetOperand(&inst_reg, operand);
//        _operand2 = atoi(operand);
        std::istringstream(operand) >> std::hex >> _operand2;
    }
    else {
        inst_reg++;
        GetOperand(&inst_reg, operand);
        _regNumber2 = atoi(operand);
    }
    
}

void Instructor::Calculate(int* reg_var){
    int opr1, opr2;
    if(_opCode < MOVE){
        //value가 직접 들어온 경우는 regNumber 변수가 -1이 되므로
        //regNumber의 값을 판단하여 operand의 종류를 확인한다.
        if(_regNumber1 == -1){
            opr1 = _operand1;
        }
        else {
            opr1 = reg_var[_regNumber1];
        }
        if(_regNumber2 == -1){
            opr2 = _operand2;
        }
        else{
            opr2 = reg_var[_regNumber2];
        }
        
        reg_var[0] = operatorPtr[_opCode](opr1,opr2);
    }
    else if( _opCode == MOVE){
        //레지스터에 값 저장인 경우 oprand2에 값이 있을것이므로 해당 값을 regNumber1에 저장
        reg_var[_regNumber1] = _operand2;
    }
    else{
        //레지스터에 값 저장인 경우 oprand2에 값이 있을것이므로 해당 값을 regNumber1에 저장 
        reg_var[_regNumber1] = reg_var[_regNumber2];
    }
}
void Instructor::SaveResult(int* reg_var, FileIO* fileManager){
    int regNumber, result, opr1, opr2;
    
    if(_opCode < MOVE){
        //value가 직접 들어온 경우는 regNumber 변수가 -1이 되므로
        //regNumber의 값을 판단하여 operand의 종류를 확인한다.
        if(_regNumber1 == -1){
            opr1 = _operand1;
        }
        else {
            opr1 = reg_var[_regNumber1];
        }
        
        if(_regNumber2 == -1){
            opr2 = _operand2;
        }
        else{
            opr2 = reg_var[_regNumber2];
        }
        
        result = reg_var[0];
        regNumber = 0;
        
        fileManager->SaveResult(regNumber, result, _operator, opr1, opr2);
    }
    else{
        //레지스터에 값 저장인 경우 oprand2에 값이 있을것이므로 해당 값을 regNumber1에 저장
        result = reg_var[_regNumber1];
        regNumber = _regNumber1;
        fileManager->SaveResult(regNumber,result);
    }
}



