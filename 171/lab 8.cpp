// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string pattern, replacement, input;
    
    
    cout<<"What's the pattern you want to look for? ";
    getline(cin, pattern);
    
    
    cout<<"What would like to replace that pattern with? ";
    getline(cin, replacement);
    
    do
    {
        
        
        cout<<"Enter a line to replace in.  Enter $$ to quit: "
        getline(cin, input);
        cout<<"input"<<endl;
        
    }
    while(input=="$$");
    return 0;
    
    
    
    
}
