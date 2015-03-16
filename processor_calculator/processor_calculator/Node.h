//
//  Node.h
//
//
//  Created by LeeChungHee on 2015. 3. 15
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#include <iostream>

class Node
{
private:
    void*   _data;
    Node*   _next;
public:
    Node();
    void    SaveData(char* inputString);
    void    SetNext(Node* next);
    void*   GetData();
    Node*   GetNext();
};
