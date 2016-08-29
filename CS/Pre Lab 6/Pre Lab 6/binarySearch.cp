
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void merge_sort(ofstream &masterfile, ifstream &file1, ifstream &file2);

int main(void)
{
    
    ifstream file1, file2;
    ofstream  masterfile;
    file1.open("DICTIONARY_45580.txt");
    file2.open("DICTIONARY_1184.txt");
    
    int count=0;
    string data,data2;
    while (file1>>data)
    {
        file1>>data;
        count ++;
        cout<<data<<endl;
    }
    
    while (file2>>data2)
    {
        file2>>data2;
        count ++;
        cout<<data2<<endl;
    }
    
    merge_sort(masterfile, file1, file2);
}



void merge_sort(ofstream &masterfile, ifstream &file1, ifstream &file2)
{
    string data1,data2;
 
    while(file1!=EOF && file2 != EOF)
    {
        masterfile <<getline(file1, data1)<<endl;
        masterfile <<getline(file2,data2)<<endl;
    }

    

}