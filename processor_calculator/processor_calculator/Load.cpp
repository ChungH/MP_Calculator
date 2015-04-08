
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
    unsigned int memoryIndex = (rsData + _immediate)/4;
    unsigned int memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedData = mask & memoryData;
    
    Instructor::SetDataToRegister(_rt, maskedData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadByteUnsigned \nR[%d] = {24b'0, M[R[%d] + %d](7:0) =>\nR[%d] = {24b'0, %d}\n==================================\n",_rt,_rs,_immediate,_rt,memoryData);
    Instructor::AppendLog(logBuf);
    
    
    return false;
}

//LoadHalfwordUnsigned class

LoadHalfwordUnsigned::LoadHalfwordUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs, rt, signExtimm){
    
}

bool LoadHalfwordUnsigned::Excution(){
    unsigned int mask = 0x0000ffff;
    unsigned int rsData   = Instructor::GetDataFromRegister(_rs);
    unsigned int memoryIndex = (rsData+_immediate)/4;
    unsigned int memoryData = Instructor::GetDataFromMemory(memoryIndex);
    unsigned int maskedData = mask & memoryData;
    
    Instructor::SetDataToRegister(_rt, maskedData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadHalfwordUnsigned \nR[%d] = {16b'0, M[R[%d] + %d](15:0) =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,memoryData);
    Instructor::AppendLog(logBuf);
    return false;
}

//LoadLinked class

LoadLinked::LoadLinked(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs, rt, signExtimm){
    
}

bool LoadLinked::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int memoryIndex = (rsData + _immediate)/4;
    unsigned int memoryData = Instructor::GetDataFromMemory(memoryIndex);
    Instructor::SetDataToRegister(_rt, memoryData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadLinked \nR[%d] = {M[R[%d] + %d] =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,memoryData);
    Instructor::AppendLog(logBuf);
    
    return false;
}


//LoadUpperImmediate class
LoadUpperImmediate::LoadUpperImmediate(unsigned int rt, unsigned int immediate) : I_Instruction(0,rt,immediate){
    
}

bool LoadUpperImmediate::Excution(){
    Instructor::SetDataToRegister(_rt, _immediate << 16);
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadUpperImmediate \nR[%d] = {%d, 16b'0} =>\nR[%d] = %x\n==================================\n",_rt,_rt,_immediate,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
    return false;
}

//LoadWord class

LoadWord::LoadWord(unsigned int rs, unsigned int rt, unsigned int signExtimm) : I_Instruction(rs,rt,signExtimm){
    
}

bool LoadWord::Excution(){
    unsigned int rsData = Instructor::GetDataFromRegister(_rs);
    unsigned int memoryIndex = (rsData + _immediate)/4;
    unsigned int memoryData = Instructor::GetDataFromMemory(memoryIndex);
    Instructor::SetDataToRegister(_rt, memoryData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadWord \nR[%d] = {M[R[%d] + %d] =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,memoryData);
    Instructor::AppendLog(logBuf);
    
    return false;
}










