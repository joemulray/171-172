

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void processor(string filename, string outputname)
{
    string section=".se";
    string center=".ce";
    string data;
    int count=0;
    int sectionNum=1;
    
    ifstream file;
    file.open(filename);
    
    ofstream outputFile;
    outputFile.open(outputname);
    
    int pagenumber=1;
    
    
    while(!file.eof())
    {
        if(count<=5)
        {
            outputFile<<endl;
        }
        if(count>5 && count<=61)
        {
            getline(file,data);
            if(center.compare(data)==0)
           {
                getline(file,data);
                outputFile<<"                              "<<data<<"                              "<<endl;
            }
            else if(section.compare(data)==0)
            {
                outputFile<<endl;
                outputFile<<endl;
                getline(file,data);
                outputFile<<sectionNum<<". "<<data<<endl;
                outputFile<<endl;
                sectionNum++;
            }
            else
                outputFile<<data<<endl;
        }
        if(count>61 && count<=63)
        {
            outputFile<<endl;
            outputFile<<endl;
        }
        if(count>63 && count<=64)
        {
            outputFile<<"Page: " <<pagenumber;
            pagenumber++    ;
        }
        if(count>64 && count<=66)
        {
            outputFile<<endl;
        }
        if(count==66)
        {
            count=0;
        }
        
        count++;
        
    }
    outputFile<<endl;
    outputFile<<endl;
    outputFile<<"Page: " <<pagenumber;
    
    
    outputFile<<endl;
    outputFile<<endl;
    
    
    file.close();
    
    
}



int main()
{
    string filename,outputname;
    
    cout<<"Enter a file name: ";
    cin>>filename;
    
    cout<<"Enter a file output name:";
    cin>>outputname;

    
    processor(filename,outputname);
    
    return 0;
    
}
