// Joseph Mulray Homework #2 January 9th 2016
#include <iostream>
#include <string>
using namespace std;

int makeCheckDigit(int x)       //Gets the Check Digit value of the Zip Code

{
    int remainder;
    int sum=0;
    int count=0;
    while(count>0)
    {
        
        sum+= x%10;
        x = x/10;
    }
    
    remainder= (10- (sum%10));
    
    if(sum==0)
        return 0;
    else
        
        return (remainder);
}

string convertDigit(int x)              //Converts integer number into their respective codes
{
    
    switch(x)
    {
        case 1:
            return(":::||");
            break;
        case 2:
            return("::|:|");
            break;
        case 3:
            return("::||:");
            break;
        case 4:
            return(":|::|");
            break;
        case 5:
            return(":|:|:");
            break;
        case 6:
            return(":||::");
            break;
        case 7:
            return("|:::|");
            break;
        case 8:
            return("|::|:");
            break;
        case 9:
            return("|:|::");
        default:
            return("||:::");
    }
}

string barcode(int zipcode)
{
    
    string barcode = "";
    
    int zip = zipcode;
    
    for(int x=5;x>0;x--)
    {
        
        barcode = convertDigit(zip%10) + barcode;       //Getting each individual letter and converting them into

        zip/=10;
    }
    
    string temp = convertDigit(makeCheckDigit(zipcode));       //Calling the makeDigit function and converting that value to a Barcode

    barcode+=temp;
    barcode="|"+barcode+"|";
    return barcode;
    
}


int main()
{
    int zipcode;
    
    cout<<"Enter your zipcode: ";           //Getting User Input
    cin>>zipcode;
    
    if(zipcode>0)
    {
        cout<<barcode(zipcode);                 //Printing barcode function after
    }
    else
        cout<<"Error";                              //If zipcode is negative value prints error.
    
    return 0;
}
