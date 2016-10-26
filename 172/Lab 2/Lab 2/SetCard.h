//
//  SetCard.h
//  Lab 2
//
//  Created by Joseph Mulray on 6/31/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//

#ifndef SetCard_h
#define SetCard_h

#include <stdio.h>


#include <iostream>
#include <string>
#include <vector>

using namespace std;


//Class Definition


//string Shading, int number
class SetCards
{
private:
    string shape_, shading_, color_;
    int number_;
    
    
public:
    
    string shape [3] {"DIAMONDS", "OVALS", "SQUIGGLES"};
    string  shading [3] {"OPEN", "LINED", "SOLID"};
    string  color [3] {"RED", "GREEN", "PURPLE"};
    int number [3] {1, 2, 3};
    
    
    
    SetCards()
    {
        vector<int> rand(4);
        
        for(int x=0;x<rand.size();x++)
        {
            rand[x] = (rand() % 3)
        }
        
        
        shape_ = shape[rand[0]];
        shading_ = shading[rand[1]];
        color_ = color[rand[2]];
        number_ = number[(rand[3]];
        
        cout<<"Shape:" <<shape_<<endl;
        cout<<"Shading:"<<shading_<<endl;
        cout<<"Color:" <<color_<<endl;
        cout<<"Number:" <<number_<<endl;
        cout<<endl;
    }
    
    int getNumber()
    {
        return number_;
    }
    
    string getShape()
    {
        return shape_;
    }
    
    string getShading()
    {
        return shading_;
    }
    
    string getColor(){
        return color_;
    }
    
    void setNumber(int x)
    {
        number_ = x;
    }
    
    void setShape(string str)
    {
        shape_=str;
    }
    
    void setShading(string str)
    {
        shading_ = str;
    }
    
};


#endif /* SetCard_hp */
