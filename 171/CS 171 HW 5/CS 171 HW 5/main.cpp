#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

void introduction(istream &is, ostream &os, string target, string replacement)
{
    
    string data,instruct;
    cout<<"Do you want instructions (y/n): ";
    os<<"Do you want instructions (y/n): ";
    cin>>instruct;
    os<<instruct<<endl;
    
    while((instruct.compare("y")==0) || instruct.compare("Y")==0)
    {
        string line;
        ifstream input;
        input.open("input.txt");
        while(!input.eof())
        {
            getline(input,data);
            cout<<data<<endl;
            os<<data<<endl;
        }
        cout<<"Do you want instructions (y/n): ";
        os<<"Do you want instructions (y/n): ";
        cin>>instruct;
        os<<instruct<<endl;
        
        
    }
    os<<endl;
    os<<"LUNAR LANDER"<<endl;
    os<<"Beginning landing procedure.........."<<endl;
    os<<"DIGBY wishes you good luck !!!!!!!"<<endl;

    cout<<endl;
    cout<<"LUNAR LANDER"<<endl;
    cout<<"Beginning landing procedure.........."<<endl;
    cout<<"DIGBY wishes you good luck !!!!!!!"<<endl;

    string in;
    
    while (getline(is, in))
    {
        while (in.find(target) != -1)
        {
            in.replace(in.find(target), target.length(), replacement);
            in.find(target);
        }
        os << in;
        if(!is.eof())
        {
            os<<"\n";
        }
    }
}

void finalAnalysis(ostream &os, double velocity)
{
    
    if (velocity <= 0)
    {
        cout << "Congratulations! A perfect landing!!" << endl ;
        cout << "Your license will be renewed.............later." << endl ;
        
        os << "Congratulations! A perfect landing!!" << endl ;
        os << "Your license will be renewed.............later." << endl ;
    }
    else if (velocity < 2)
    {
        cout << "A little bumpy." << endl ;
        os << "A little bumpy." << endl ;
    }
    else if (velocity < 5)
    {
        cout << "You blew it!!!!!!" << endl ;
        cout << "Your family will be notified..............by post." << endl ;
        os << "You blew it!!!!!!" << endl ;
        os << "Your family will be notified..............by post." << endl ;
    }
    else if (velocity < 10)
    {
        
        cout << "Your ship is a heap of junk !!!!!" << endl ;
        cout << "Your family will be notified..............by post." << endl ;
        os << "Your ship is a heap of junk !!!!!" << endl ;
        os << "Your family will be notified..............by post." << endl ;
    }
    else if (velocity < 30)
    {
        cout << "You blasted a huge crater !!!!!" << endl ;
        cout << "Your family will be notified..............by post." << endl ;
   
        os << "You blasted a huge crater !!!!!" << endl ;
        os << "Your family will be notified..............by post." << endl ;
    }
    else if (velocity < 50)
    {
        cout << "Your ship is a wreck !!!!!" << endl ;
        cout << "Your family will be notified..............by post." << endl ;

        os << "Your ship is a wreck !!!!!" << endl ;
        os << "Your family will be notified..............by post." << endl ;
    }
    else
    {
        cout << "You totaled an entire mountain !!!!!" << endl ;
        cout<< "Your family will be notified..............by post." << endl ;

        os << "You totaled an entire mountain !!!!!" << endl ;
        os << "Your family will be notified..............by post." << endl ;
    }
    
}


void touchdown(double &elapsedTime, double &velocity, double &burnAmount, double &height)
{
    
    double alpha;
    alpha = (sqrt(pow(velocity,2)+height*(10-2*burnAmount))-velocity)/(5-burnAmount);
    elapsedTime += alpha;
    velocity = velocity + (5-burnAmount) * alpha;
    if(height<0)
        height=0;
    
}

void reportStatus(ostream &os, double elapsedTime, double height, double velocity, double fuel, string name)
{
    
    cout<<"Status of your " <<name<< " spacecraft: "<<endl;
    cout<<"Time: "<<elapsedTime <<endl;
    cout<<"Height: "<<height<<endl;
    cout<<"Speed : " <<velocity<<endl;
    cout<<"Fuel Left: "<<fuel<<endl;
    cout<<endl;
    
    os<<"Status of your " <<name << " spacecraft: "<<endl;
    os<<"Time: "<<elapsedTime <<endl;
    os<<"Height: "<<height<<endl;
    os<<"Speed : " <<velocity<<endl;
    os<<"Fuel Left: "<<fuel<<endl;
    os<<endl;
    
}
void updateStatus(double &velocity, double burnAmount, double &fuelRemaining, double &height)
{
    double v2 = velocity;
    velocity = velocity+5-burnAmount;
    height = height - (v2+velocity)/2;
    fuelRemaining=fuelRemaining-burnAmount;

    
}


int main()
{
     double height=1000;
     double velocity=50;
     double fuelRemaining=150;
     double burnAmount=0;
    double elapsedTime=0;
     ofstream os;
     ifstream is;
     string name,inputfile;
    
    
    cout<<"Enter a file name to log session: ";
    cin>>inputfile;
    os.open(inputfile);
    
    
    introduction(is, os,"$SPACECRAFT", "APOLLO");
    while (height > 0)
    {
        reportStatus(os, elapsedTime, height, velocity, fuelRemaining, "APOLLO");


        if (fuelRemaining > 0)
        {
            cout << "Enter fuel burn amount: " ;
            os << "Enter fuel burn amount: " ;
            cin >> burnAmount ;
            os<<burnAmount<<endl;
            
            
            if( burnAmount < 0 )
                burnAmount = 0;
            if( burnAmount > fuelRemaining )
                burnAmount = fuelRemaining;
        }
        else
        {
            cout << "**** OUT OF FUEL ****" << endl ;
            burnAmount = 0;
        }
    

    updateStatus(velocity, burnAmount, fuelRemaining, height);
        elapsedTime++;
    
    }
    touchdown(elapsedTime, velocity,burnAmount, height);
    cout<<endl;
    cout<<"***** CONTACT *****"<<endl;
    cout<<"Touchdown at "<<elapsedTime<<" seconds.";
    cout<<"Landing Velocity = " << velocity<<endl;
    cout<<fuelRemaining<<" units of fuel remaining."<<endl;
    cout<<endl;
    
    os<<endl;
    os<<"***** CONTACT *****"<<endl;
    os<<"Touchdown at "<<elapsedTime<<" seconds.";
    os<<"Landing Velocity = " << velocity<<endl;
    os<<fuelRemaining<<" units of fuel remaining."<<endl;
    os<<endl;
    
    
    finalAnalysis(os, velocity);
    os.close();
    return 0;
    
}