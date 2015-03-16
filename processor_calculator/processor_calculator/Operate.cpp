//
//  Operate.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 14..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Operate.h"

Operate::Operate(){
    
}

Operate::~Operate(){
    
}

int Operate::Sum(const int operand1,const int operand2){
    return operand1+operand2;
}

int Operate::Sub(const int operand1,const int operand2){
    return operand1-operand2;
}

int Operate::Mul(const int operand1,const int operand2){
    return operand1*operand2;
}

int Operate::Div(const int operand1,const int operand2){
    return operand1/operand2;
}

int Operate::Mod(const int operand1,const int operand2){
    return operand1%operand2;
}


void Operate::Move(int* reg,const int value){
    *reg = value;
}

void Operate::Move(int* reg1, int* reg2){
    *reg1 = *reg2;
}



