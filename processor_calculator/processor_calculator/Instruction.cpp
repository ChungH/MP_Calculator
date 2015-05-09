//
//  Instruction.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Instruction.h"
Instruction::Instruction(int instType) : _instType(instType){
    
}

R_Instruction::R_Instruction(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int funct, unsigned int rsData, unsigned int rtData) : Instruction(Instructiontype::R_Type), _shamt(shamt), _funct(funct), _rsData(rsData), _rtData(rtData),_rdData(-1){
    
}

I_Instruction::I_Instruction(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData) : Instruction(Instructiontype::I_Type), _immediate(immediate), _rsData(rsData), _rtData(rtData){
    
}

J_Instruction::J_Instruction(unsigned int address): Instruction(Instructiontype::J_Type), _address(address){
    
}

