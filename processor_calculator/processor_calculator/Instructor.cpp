//
//  Instructor.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Instructor.h"

Instructor::Instructor(){
    opCode      = 0;
    regNumber1  = -1;
    regNumber2  = -1;
    operand1    = -1;
    operand2    = -1;
}

Instructor::~Instructor(){
    
}

bool Instructor::ExcuteInstruction(char* inst_reg,int* reg_var){
    opCode      = 0;
    regNumber1  = -1;
    regNumber2  = -1;
    operand1    = -1;
    operand2    = -1;
    InterpretOpCode(inst_reg);
    if(opCode == ERROR){
        return false;
    }
    InterpretOperand(inst_reg);
    Calculate(reg_var);
    return true;
}


void Instructor::InterpretOpCode(char* inst_reg){
    switch (*inst_reg) {
        case '+':
            opCode = SUM;
            return;
            
        case '-':
            opCode = SUB;
            return;
            
        case '*':
            opCode = MUL;
            return;
            
        case '/':
            opCode = DIV;
            return;
            
        case '%':
            opCode = MOD;
            return;
            
        case 'M':
            inst_reg+=2;
            while(*inst_reg != ' ')
                inst_reg++;
            inst_reg++;
            if(*inst_reg == 'R') {
                opCode = MOVER;
                return;
            }
            else {
                opCode = MOVE;
                return;
            }
            
        default:
            opCode = ERROR;
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
        operand1 = atoi(operand);
    }
    else {
        inst_reg++;
        GetOperand(&inst_reg, operand);
        regNumber1 = atoi(operand);
    }
    
    //find operand2
    while (*inst_reg!= '0' && *inst_reg != 'R')
        inst_reg++;
    
    if(*inst_reg == '0') {
        inst_reg+=2;
        GetOperand(&inst_reg, operand);
        operand2 = atoi(operand);
    }
    else {
        inst_reg++;
        GetOperand(&inst_reg, operand);
        regNumber2 = atoi(operand);
    }
    
}

void Instructor::Calculate(int* reg_var){
    int opr1, opr2;
    if(opCode < MOVE){
        //value가 직접 들어온 경우는 regNumber 변수가 -1이 되므로
        //regNumber의 값을 판단하여 operand의 종류를 확인한다.
        if(regNumber1 == -1){
            opr1 = operand1;
        }
        else {
            opr1 = reg_var[regNumber1];
        }
        if(regNumber2 == -1){
            opr2 = operand2;
        }
        else{
            opr2 = reg_var[regNumber2];
        }
        
        reg_var[0] = operatorPtr[opCode](opr1,opr2);
    }
    else if( opCode == MOVE){
        //레지스터에 값 저장인 경우 oprand2에 값이 있을것이므로 해당 값을 regNumber1에 저장
        reg_var[regNumber1] = operand2;
    }
    else{
        //레지스터에 값 저장인 경우 oprand2에 값이 있을것이므로 해당 값을 regNumber1에 저장 
        reg_var[regNumber1] = reg_var[regNumber2];
    }
}



