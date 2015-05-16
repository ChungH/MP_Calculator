
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

LoadByteUnsigned::LoadByteUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm, unsigned int rsData) : I_Instruction(rs, rt, signExtimm,rsData,-1){
    
}

bool LoadByteUnsigned::Execution(){
    return false;
}
void LoadByteUnsigned::MemoryAccess(){
    unsigned int mask = 0x000000ff;
    unsigned int memoryIndex = (_rsData + _immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    _maskedData = mask & _memoryData;
}
void LoadByteUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rt, _maskedData);
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadByteUnsigned \nR[%d] = {24b'0, M[R[%d] + %d](7:0) =>\nR[%d] = {24b'0, %d}\n==================================\n",_rt,_rs,_immediate,_rt,_memoryData);
    Instructor::AppendLog(logBuf);
    
    
}

//LoadHalfwordUnsigned class

LoadHalfwordUnsigned::LoadHalfwordUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm,unsigned int rsData) : I_Instruction(rs, rt, signExtimm,rsData,-1){
    
}

bool LoadHalfwordUnsigned::Execution(){

    return false;
}
void LoadHalfwordUnsigned::MemoryAccess(){
    unsigned int mask = 0x0000ffff;
    unsigned int memoryIndex = (_rsData+_immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    _maskedData = mask & _memoryData;
    _rtData = _maskedData;
    
}
void LoadHalfwordUnsigned::WriteBack(){
     Instructor::SetDataToRegister(_rt, _rtData);
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadHalfwordUnsigned \nR[%d] = {16b'0, M[R[%d] + %d](15:0) =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,_memoryData);
    Instructor::AppendLog(logBuf);
}
//LoadLinked class

LoadLinked::LoadLinked(unsigned int rs, unsigned int rt, unsigned int signExtimm,unsigned int rsData) : I_Instruction(rs, rt, signExtimm,rsData,-1){
}

bool LoadLinked::Execution(){

    return false;
}
void LoadLinked::MemoryAccess(){
    unsigned int memoryIndex = (_rsData + _immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    _rtData = _memoryData;
    
}
void LoadLinked::WriteBack(){
     Instructor::SetDataToRegister(_rt, _rtData);
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadLinked \nR[%d] = {M[R[%d] + %d] =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,_memoryData);
    Instructor::AppendLog(logBuf);
    
}

//LoadUpperImmediate class
LoadUpperImmediate::LoadUpperImmediate(unsigned int rt, unsigned int immediate) : I_Instruction(0,rt,immediate,-1,-1){
}

bool LoadUpperImmediate::Execution(){
    
    _maskedData = _immediate << 16;
    _rtData = _maskedData;

    return false;
}
void LoadUpperImmediate::MemoryAccess(){
    
}
void LoadUpperImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadUpperImmediate \nR[%d] = {%d, 16b'0} =>\nR[%d] = %x\n==================================\n",_rt,_rt,_immediate,Instructor::GetDataFromRegister(_rt));
    Instructor::AppendLog(logBuf);
}
//LoadWord class

LoadWord::LoadWord(unsigned int rs, unsigned int rt, unsigned int signExtimm,unsigned int rsData) : I_Instruction(rs,rt,signExtimm,rsData,-1){
}

bool LoadWord::Execution(){

    return false;
}
void LoadWord::MemoryAccess(){
    unsigned int memoryIndex = (_rsData + _immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    _rtData = _memoryData;
}
void LoadWord::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    char logBuf[100];
    sprintf(logBuf, "Instruction : LoadWord \nR[%d] = {M[R[%d] + %d] =>\nR[%d] = %d\n==================================\n",_rt,_rs,_immediate,_rt,_memoryData);
    Instructor::AppendLog(logBuf);
    
}









