//
//  Grid.hpp
//  Homework 3
//
//  Created by Joseph Mulray on 8/3/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//

#ifndef __Grid_h__
#define __Grid_h__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Grid {
    public:
    
    
    //---------Constructors------------
    Grid();
    
    //-----------Inspectors------------
    
    bool isLegalMove(int startPosRow,int startPosColumn, int endPosRow, int endPosColumn);
    bool isWinner();
    //----------Mutator--------------
    
    void startPosition(int startPosRow, int startPosColumn);
    void applyMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn);
    
    //-----------Output--------------
    void display();
    
private:
    vector< vector<int> > grid_;

    
    
};

#endif /* Grid_h */
