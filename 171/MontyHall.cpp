// Joseph Mulray
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

int stay(char door1, char door2, char door3, int doorPlayer)
{
    int count=0;
    int num=0;
    if(door1=='C')
        num=1;
    else if(door2=='C')
        num=2;
    else if(door3=='C')
        num=3;
    
    if(doorPlayer==num)
        count++;
    
    return count;
}

void setupDoors(char &door1, char &door2, char &door3)
{
    int num;
    
    num=(rand() % 3 + 1);
    if(num==1)
    {
        door1='G';
        door2='G';
        door3= 'C';
    }
    else if(num==2)
    {
        door1='G';
        door2='C';
        door3= 'G';
    }
    else if(num==3)
    {
        door1='C';
        door2='G';
        door3= 'G';
    }
    
}



void pickDoorChoices(char door1, char door2, char door3, int &doorPlayer, int &doorMonty)
{
    int num=0;
    if(door1=='C')
        num=1;
    else if(door2=='C')
        num=2;
    else if(door3=='C')
        num=3;
    
    doorPlayer = (rand() % 3 + 1);
    do
    {
        doorMonty = (rand() % 3 + 1);
    }while((doorMonty==num) || (doorMonty==doorPlayer));
    
}




int main()
{
    
    srand(time(NULL));
    char door1, door2, door3;
    int doorPlayer, doorMonty;
    int staying=0;
    double total =10000;
    
    for(int x=0; x<total;x++)
    {
        setupDoors(door1, door2, door3);
        pickDoorChoices(door1, door2, door3, doorPlayer, doorMonty);
        staying+=stay(door1, door2, door3, doorPlayer);
    }
    double a = (staying/total) * 100;
    double b = (total-staying) / total * 100;
    
    cout<<"Staying: " <<a<<"%"<<endl;
    cout<<"Switching: " <<b<<"%"<<endl;
    
    
}