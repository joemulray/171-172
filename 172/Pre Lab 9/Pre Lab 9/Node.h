//
//  Node.cpp
//  Pre Lab 9
//
//  Created by Joseph Mulray on 8/16/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#ifndef  __Node__
#define __Node__
class Node
{
public:
    Node(int d = 0, Node * N = NULL);
    
    int Data() const;
    void Data(int d);
    
    Node * Next() const;
    void Next(Node * N);
private:
    int Data_;
    Node * Next_;
};

#endif