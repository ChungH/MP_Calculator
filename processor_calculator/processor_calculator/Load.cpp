
//
//  Load.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 29..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Load.h"
#include "Instructor.h"

//LoadByteUnsigned class

LoadByteUnsigned::LoadByteUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs, rt, signExtimm){
    
}

bool LoadByteUnsigned::Excution(){
    unsigned int mask = 0x000000ff;
    unsigned int rsData   = Instructor::GetDataFromRegister(_rs);
    unsigned int memoryIndex = rsData + _immediate;
    unsigned int memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedData = mask & memoryData;
    
    Instructor::SetDataToRegister(_rt, maskedData);
    return false;
}

//LoadHalfwordUnsigned class

LoadHalfwordUnsigned::LoadHalfwordUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs, rt, signExtimm){
    
}

bool LoadHalfwordUnsigned::Excution(){
    unsigned int mask = 0x0000ffff;
    unsigned int rsData   = Instructor::GetDataFromRegister(_rs);
    unsigned int memoryData = Instructor::GetDataFromMemory(rsData);
    unsigned int resultData = memoryData + _immediate;
    unsigned int maskedData = mask & resultData;
    
    Instructor::SetDataToRegister(_rt, maskedData);
    return false;
}

//LoadLinked class

LoadLinked::LoadLinked(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs, rt, signExtimm){
    
}

bool LoadLinked::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int memoryIndex = rsData + _immediate;
    unsigned int memoryData = Instructor::GetDataFromRegister(memoryIndex);
    Instructor::SetDataToRegister(_rt, memoryData);
    return false;
}


//LoadUpperImmediate class
LoadUpperImmediate::LoadUpperImmediate(unsigned int rt, unsigned int immediate) : I_Instruction(0,rt,immediate){
    
}

bool LoadUpperImmediate::Excution(){
    Instructor::SetDataToRegister(_rt, _immediate << 16);
    return false;
}

//LoadWord class

LoadWord::LoadWord(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs,rt,signExtimm){
    
}

bool LoadWord::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int memoryIndex = rsData + _immediate;
    unsigned int memoryData = Instructor::GetDataFromRegister(memoryIndex);
    Instructor::SetDataToRegister(_rt, memoryData);
    return false;
}










