//
//  Instruction.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Instruction.h"
Instruction::Instruction(int instType, unsigned int rs, unsigned int  rt, unsigned int rd, unsigned int rsData, unsigned int rtData) : _instType(instType), _writeChk(true), _rs(rs), _rt(rt), _rd(rd), _rsData(rsData), _rtData(rtData), _rdData(-1){
}

R_Instruction::R_Instruction(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int funct, unsigned int rsData, unsigned int rtData) : Instruction(Instructiontype::R_Type, rs, rt, rd, rsData, rtData),_shamt(shamt), _funct(funct){
    
}

I_Instruction::I_Instruction(unsigned int rs, unsigned int rt, unsigned int immediate, unsigned int rsData, unsigned int rtData) : Instruction(Instructiontype::I_Type,rs,rt,-1,rsData,rtData), _immediate(immediate){
    
}

J_Instruction::J_Instruction(unsigned int address): Instruction(Instructiontype::J_Type,-1,-1,-1,-1,-1), _address(address){
    
}

