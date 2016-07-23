// Joseph Mulray
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void computeBloodAlcoholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC)
{
    femaleBAC=0;
    maleBAC=0;
    double x= numDrinks;
    float temp;
    float time=duration;
    time=  float ((time/40)/100);
    temp= double (x/weight);
    
    
    double total = (temp*3.8) - time;
    if(total<0)
        total=0;
    
    maleBAC = total;
    
    double total2= (temp*4.5)- time;
    if(total2<0)
        total2=0;
    
    femaleBAC=total2;
}



int promptForInteger (string const &message, int lower, int upper)
{
    
    do
    {
        cout<<message;
        cin>>upper;
        if(upper>=lower)
            return upper;
    }while(upper<lower);
    return upper;
}
char promptForMorF(string const &message)
{   char sex;
    
    do
    {
        cout<<message;
        cin>>sex;
    }
    while(sex!='M' && sex!='F');
    
    return sex;
}

string impairment(double bac)
{
    const double safe = 0.00;
    const double someImpairment = 0.04;
    const double significantAffected = 0.08;
    const double someCriminalPenalties = 0.10;
    const double deathPossible = 0.30;
    const string SAFE = "Safe To Drive";
    const string SOMEIMPAIR = "Some Impairment";
    const string SIGNIFICANT = "Driving Skills Significantly Affected";
    const string MOST_STATES = "Criminal Penalties in Most US States";
    const string ALL_STATES = "Legally Intoxicated - Criminal Penalties in All US States";
    const string YOURE_DEAD = "Death is Possible!";
    
    
    if(bac==safe)
    {
        return(SAFE);
    }
    else if(bac<someImpairment)
    {
        return(SOMEIMPAIR);
    }
    else if(bac<significantAffected)
    {
        return(SIGNIFICANT);
    }
    else if(bac<someCriminalPenalties)
    {
        return(MOST_STATES);
    }
    else if(bac<=deathPossible)
    {
        return(ALL_STATES);
    }
    else
    {
        return(YOURE_DEAD);
    }
}

void showImpairmentChart(int weight, int duration, bool isMale)
{
    double maleBAC,femaleBAC;
    
    if (isMale==true)
    {
        cout<<"#Drinks     BAC status"<<endl;
        for(int x=0; x<=10;x++)
        {
            computeBloodAlcoholConcentration(x, weight, duration,maleBAC,femaleBAC);
            cout<<x << "    " <<setprecision(3)<<maleBAC<<"  " <<impairment(maleBAC) <<endl;
        }
        
    }
    else
    {
        cout<<"#Drinks     BAC status"<<endl;
        for(int x=0; x<=10;x++)
        {
            computeBloodAlcoholConcentration(x, weight, duration, maleBAC, femaleBAC);
            cout<<x << "    " <<setprecision(3)<<femaleBAC<< "  " <<impairment(maleBAC) <<endl;
        }
    }
    
}

int main()          //**************Main function***************//
{
    
    int weight,duration;
    char sex;
    string gender;
    bool isMale;
    
    
    
    weight=promptForInteger ("Enter your weight (in lbs): ", 0, 1);
    duration=promptForInteger ("Enter time since last drink (in minutes): ", 0, 1);
    
    sex =promptForMorF("Enter your sex as M or F: ");
    
    if(sex=='M')
    {
        isMale=true;
        gender="male";
    }
    else
    {
        isMale=false;
        gender= "female";
    }
    
    cout<<weight << " pound, " << gender<<endl;
    showImpairmentChart(weight, duration, isMale);
    
}
