//
//  Grid.cpp
//  Homework 3
//
//  Created by Joseph Mulray on 8/3/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//

#include "Grid.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;



Grid::Grid()
{
    //Initializing the grid of vector
    for (int i = 0; i < 4; i++)
    {
        vector<int> grid;
        for (int x = 0; x < 4; x++)
        {
            grid.push_back(1);
        }
        
        grid_.push_back(grid);
    }
}

void Grid::display()
{
    //Display the Grid board.
    cout<<endl;
    cout << "     0  1  2  3" << endl;
    cout << "  +-------------+" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < 4; j++)
        {
            if (grid_[i][j] == 1)
                cout << " X ";
            else
                cout << " O ";
        }
        cout << "| " << endl;
    }
    cout << "  +-------------+" << endl;
    cout<<endl;

}

void Grid::startPosition(int startPosRow, int startPosColumn)
{
    grid_[startPosRow][startPosColumn]=0;
}

void Grid::applyMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn)
{
    // testing to see if point is valid first. if not get another input
    
    bool isTrue;
    isTrue = isLegalMove(startPosRow, startPosColumn, endPosRow, endPosColumn);
    if (isTrue == true)
    {
        int rowMiddle = (startPosRow + endPosRow) / 2;
        int columnMiddle = (startPosColumn + endPosColumn) / 2;
        
        grid_[startPosRow][startPosColumn] = 0;
        grid_[rowMiddle][columnMiddle] = 0;
        grid_[endPosRow][endPosColumn] = 1;
        
    }
    else
    {
        //use recursion to call function again if answer is invalid.
        cout<<"Invalid move, please try again.\n"<<endl;
        display();
        cout<<"Enter move: ";
        cin>>startPosRow>>startPosColumn>>endPosRow>>endPosColumn;
        applyMove(startPosRow , startPosColumn, endPosRow, endPosColumn);
    }
}

bool Grid:: isWinner()
{
    //returns a bool depeding on if board is filled with pegs or not
    //returns true if board is filled else returns false.
    int count =0;
    
    for (int i = 0; i < 4; i++)
    {
        
        for (int j = 0; j < 4; j++)
        {
            
            if (grid_[i][j] == 0)
                count++;
        }
    }
    
    if (count == 16)// If every number on the board is O count == number of pegs on board
        return true;
    else
        return false;
}
bool Grid::isLegalMove(int startPosRow,int startPosColumn, int endPosRow, int endPosColumn)
{
    
    int rowMiddle = (startPosRow + endPosRow) / 2;
    int columnMiddle = (startPosColumn + endPosColumn) / 2;
    
    
    //Testing if any of the points are out of range of the board.
    if ((startPosRow > 3) || (startPosColumn > 3))
        return false;
    else if ((startPosRow < 0) || (startPosColumn < 0))
        return false;
    else if ((endPosRow > 3) || (endPosColumn > 3))
        return false;
    else if ((endPosRow < 0) || (endPosColumn < 0))
        return false;

    
    //checking if grid position is not already taken by a peg
    if (grid_[startPosRow][startPosColumn] == 0)
    {
        return false;
    }
    
    //checking peg exists in middle row and columns.
    if (grid_[rowMiddle][columnMiddle] == 0)
        return false;
    else
        return true;
    
}