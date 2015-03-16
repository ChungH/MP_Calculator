//
//  Node.cpp
//
//
//  Created by LeeChungHee on 2015. 3. 15
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include "Node.h"

Node::Node()
{
    _data = NULL;
    _next = NULL;
}

void Node::SaveData(char* inputString)
{
    _data = new char(strlen(inputString)+1);
    strcpy((char*)_data,inputString);
}

void Node::SetNext(Node* next)
{
    _next = next;
}

void* Node::GetData()
{
    return _data;
}

Node* Node::GetNext()
{
    return _next;
}