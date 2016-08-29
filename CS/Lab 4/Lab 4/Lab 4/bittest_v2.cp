#include <iostream>
#include <string>
#include <stdlib.h>
#include <bitset>
#include <time.h>
using namespace std;

int main(void)
{
    srand (time(NULL));
    bitset<4> Bit ;
    cout<<"BIT"<<Bit<<endl;
    int count = 0;
    while (Bit!= 1111)
    {
        int num	= rand() % 4;
    switch (num)
        {
    case 0: Bit.flip(0);
        break;
    case 1: Bit.flip(1);
        break;
    case 2: Bit.flip(2);
        break;
    case 3: Bit.flip(3);
        break;
        }
                
        count ++;
        
    }
    
    cout<<"count"<<count<<endl;
    cout<<(Bit)<<endl;
    return 0;
}