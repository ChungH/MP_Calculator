//  InstructionSet.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 3. 25..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once

namespace Instructiontype {
    enum InstructionType : int {
        R_Type,
        I_Type,
        J_Type
    };
}

namespace Opcode {
    enum OpCode  : unsigned int {   //I, J Type Operations
        //I Type
        AddImmediate                    = 0x8,
        AddImmediateUnsigned            = 0x9,
        AndImmediate                    = 0xc,
        BranchOnEqual                   = 0x4,
        BranchOnNotEqual                = 0x5,
        LoadByteUnsigned                = 0x24,
        LoadHalfwordUnsigned            = 0x25,
        LoadLinked                      = 0x30,
        LoadUpperImmediate              = 0xf,
        LoadWord                        = 0x23,
        OrImmediate                     = 0xd,
        SetLessThanImmediate            = 0xa,
        SetLessThanImmediateUnsigned    = 0xb,
        StoreByte                       = 0x28,
        StoreConditional                = 0x38,
        StoreHalfWord                   = 0x29,
        StoreWord                       = 0x2b,
        
        //J Type
        Jump                            = 0x2,
        JumpAndLink                     = 0x3,
    
        //Multiply - 32bit
        Multiply32Bit                   = 0x1c
    
    };
}

namespace Funct {
    enum Funct : unsigned int {    //R Type Operations
        Add                             = 0x20,
        AddUnsigned                     = 0x21,
        And                             = 0x24,
        JumpRegister                    = 0x08,
        Nor                             = 0x27,
        Or                              = 0x25,
        SetLessThan                     = 0x2a,
        SetLessThanUnsigned             = 0x2b,
        ShiftLeftLogical                = 0x00,
        ShiftRightLogical               = 0x02,
        Subtract                        = 0x22,
        SubtractUnsigned                = 0x23,
        Divide                          = 0x1a,
        DivideUnsigned                  = 0x1b,
        MoveFromHi                      = 0x10,
        MoveFromLo                      = 0x12,
        MoveToHi                        = 0x11,
        MoveToLo                        = 0x13,
        Multiply                        = 0x18,
        MultiplyUnsigned                = 0x19,
        Multiply32Bit                   = 0x02
    };
}



