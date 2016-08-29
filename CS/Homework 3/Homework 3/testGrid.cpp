//
//  testGrid.cpp
//  Homework 3
//
//  Created by Joseph Mulray on 8/3/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Grid.h"
using namespace std;




int main(void)
{
    //initialize object and values
    Grid gridgame;
    int startPosRow , startPosColumn, endPosRow, endPosColumn, quit;
    quit = 81;
    
    cout<<"WELCOME TO THE SQUAREPEG GAME: \n"<<endl;
    
    //Display gridboard.
    gridgame.display();
    
    //Get initial starting point.
    cout<<"Which peg should be\nremoved to start? ";
    cin>>startPosRow>>startPosColumn;
    while(startPosRow>3 || startPosColumn>3)
    {
        cout<<"Invalid move, please try again.\n"<<endl;
        cout<<"Which peg should be\nremoved to start? ";
        cin>>startPosRow>>startPosColumn;
    }
    gridgame.startPosition(startPosRow,startPosColumn);
    
    
    //Run the game until the board until user wins. or if the first input is Q;
    while((gridgame.isWinner()==false))
    {
        
    gridgame.display();
    cout<<"Enter move: ";
    cin>>startPosRow>>startPosColumn>>endPosRow>>endPosColumn;
    gridgame.applyMove(startPosRow , startPosColumn, endPosRow, endPosColumn);
    gridgame.display();
        
    }
    
    //If user wins display message.
    if(gridgame.isWinner() == true)
        
    {   cout<<"***************************"<<endl;
        cout<<"Congratulations you've won!"<<endl;
        cout<<"***************************"<<endl;
        
    }
    return 0;
}
