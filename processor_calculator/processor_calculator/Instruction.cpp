//
//  Instruction.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Instruction.h"

R_Instruction::R_Instruction(unsigned int opcode, unsigned int rs, unsigned int rd, unsigned int shamt, unsigned int funct) : Instruction(), _opcode(opcode), _rs(rs), _rd(rd), _shamt(shamt), _funct(funct){
    
}

I_Instruction::I_Instruction(unsigned int opcode, unsigned int rs, unsigned int rt, unsigned int immediate) : _opcode(opcode), _rs(rs), _rt(rt), _immediate(immediate){
    
}

J_Instruction::J_Instruction(unsigned int opcode, unsigned int address): _opcode(opcode), _address(address){
    
}
