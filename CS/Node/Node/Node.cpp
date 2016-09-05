//
//  Node.cpp
//  Node
//
//  Created by Joseph Mulray on 8/30/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//
#include "Node.h"
#include <stdio.h>
#include <iostream>
using namespace std;


Node::Node(int d, Node * N)
{
    Data(d);
    Next(N);
}

int Node::Data() const
{
    return Data_;
}

void Node::Data(int d)
{
    Data_ = d;
}

Node * Node::Next() const
{
    return Next_;
}

void Node::Next(Node * N)
{
    Next_ = N;
}
ostream& operator << (ostream& out, Node * N)
{
    
    out << N->Data();
    return out;
    
}