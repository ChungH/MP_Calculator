
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
    Instructor::AppendLog("LBU,");
    return false;
}
void LoadByteUnsigned::MemoryAccess(){
    unsigned int mask = 0x000000ff;
    unsigned int memoryIndex = (_rsData + _immediate)/4;
//    unsigned int memoryIndex = (_rsData + _immediate);
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    _maskedData = mask & _memoryData;
    
    Instructor::AppendLog("LBU,");
}
void LoadByteUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rt, _maskedData);
    
    Instructor::AppendLog("LBU,");
}

//LoadHalfwordUnsigned class

LoadHalfwordUnsigned::LoadHalfwordUnsigned(unsigned int rs, unsigned int rt, unsigned int signExtimm,unsigned int rsData) : I_Instruction(rs, rt, signExtimm,rsData,-1){
    
}

bool LoadHalfwordUnsigned::Execution(){
    Instructor::AppendLog("LHU,");
    return false;
}
void LoadHalfwordUnsigned::MemoryAccess(){
    unsigned int mask = 0x0000ffff;
    unsigned int memoryIndex = (_rsData+_immediate)/4;
//    unsigned int memoryIndex = (_rsData + _immediate);
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    _maskedData = mask & _memoryData;
    _rtData = _maskedData;
    
    Instructor::AppendLog("LHU,");
    
}
void LoadHalfwordUnsigned::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("LHU,");
}
//LoadLinked class

LoadLinked::LoadLinked(unsigned int rs, unsigned int rt, unsigned int signExtimm,unsigned int rsData) : I_Instruction(rs, rt, signExtimm,rsData,-1){
}

bool LoadLinked::Execution(){
    Instructor::AppendLog("LL,");
    return false;
}
void LoadLinked::MemoryAccess(){
    unsigned int memoryIndex = (_rsData + _immediate)/4;
//    unsigned int memoryIndex = (_rsData + _immediate);
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
    _rtData = _memoryData;
    
    Instructor::AppendLog("LL,");
    
}
void LoadLinked::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("LL,");
    
}

//LoadUpperImmediate class
LoadUpperImmediate::LoadUpperImmediate(unsigned int rt, unsigned int immediate) : I_Instruction(0,rt,immediate,-1,-1){
}

bool LoadUpperImmediate::Execution(){
    
    _maskedData = _immediate << 16;
    _rtData = _maskedData;
    
    Instructor::AppendLog("LUI,");
    return false;
}
void LoadUpperImmediate::MemoryAccess(){
    Instructor::AppendLog("LUI,");
}
void LoadUpperImmediate::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("LUI,");
}
//LoadWord class

LoadWord::LoadWord(unsigned int rs, unsigned int rt, unsigned int signExtimm,unsigned int rsData) : I_Instruction(rs,rt,signExtimm,rsData,-1){
}

bool LoadWord::Execution(){
    Instructor::AppendLog("LW,");
    return false;
}
void LoadWord::MemoryAccess(){

    unsigned int memoryIndex = (_rsData + _immediate)/4;
    _memoryData = Instructor::GetDataFromMemory(memoryIndex);
//    unsigned int memoryIndex = (_rsData + _immediate);
//     _memoryData = Instructor::GetDataFromCache(memoryIndex);
    _rtData = _memoryData;
    
    Instructor::AppendLog("LW,");
}
void LoadWord::WriteBack(){
    Instructor::SetDataToRegister(_rt, _rtData);
    
    Instructor::AppendLog("LW,");
}









