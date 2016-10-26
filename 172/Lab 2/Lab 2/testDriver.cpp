//
//  testDriver.cpp
//  Lab 2
//
//  Created by Joseph Mulray on 7/3/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "SetCard.h"
using namespace std;


void checkSet(SetCards card1, SetCards card2, SetCards card3)
{
    bool number = false;
    bool color = false;
    bool shading = false;
    bool shape = false;
    
    if(card1.getNumber() == card2.getNumber() && card3.getNumber() == card2.getNumber())
    {
        number=true;
    }
    else if (card1.getNumber()!= card2.getNumber() && card2.getNumber()!= card3.getNumber())
    {
        number = true;
    }
    if(card1.getColor() == card2.getColor() && card3.getColor() == card2.getColor())
    {
        color = true;
    }
    else if (card1.getColor()!= card2.getColor() && card2.getColor()!= card3.getColor())
    {
        color=true;
    }
    if(card1.getShading() == card2.getShading() && card3.getShading() == card2.getShading())
    {
        shading = true;
    }
    else if (card1.getShading()!= card2.getShading() && card2.getShading()!= card3.getShading())
    {
        shading = true;
    }
    if(card1.getShape() == card2.getShape() && card3.getShape() == card2.getShape())
    {
        shape = true;
    }
    else if (card1.getShape()!= card2.getShape() && card2.getShape()!= card3.getShape())
    {
        shape = true;
    }
    
    if ((number==true &&  color==true) && (shading==true &&  shape == true))
        cout<<"You have a set!"<<endl;
    else
        cout<<"You do not have a set"<<endl;
    

}



int main()
{
    
    SetCards card1;
    SetCards card2;
    SetCards card3;
    
    checkSet(card1, card2, card3);
    
    return 0;
    
}

