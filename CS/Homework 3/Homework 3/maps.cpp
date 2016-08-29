#include <iostream>
#include <string>
#include <map>

using namespace std;
int main(void)
{

//Declare mappiing and its attributes
map <string, string> text;
text["YOLO"] = "You only live once";
text["LOL"] = "Laugh out loud";
text["ROTFL"] = "Rolling on the floor laughing";
text["CUL8R"] = "See you later";
text["LTNS"] = "Long time no see";

string input;

//output and input for mapping

cout<<"LOL: "<< text["LOL"]<<endl;
cout<<"Please enter an abbrivation:";
cin>>input;
if(text.count(input) == 1){
	cout<<input<< " means: " <<text[input]<<endl;
}
else
	cout<<"Abbrivation not found."<<endl;



return 0;
}