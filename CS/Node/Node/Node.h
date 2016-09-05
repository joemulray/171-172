#include <iostream>
#include <string>
using namespace std;


#ifndef Node_h
#define Node_h

class Node
{
public:
    Node(int d = 0, Node * N = NULL);
    
    int Data() const;
    void Data(int d);
    
    Node * Next() const;
    void Next(Node * N);
private:
    int Data_;
    Node * Next_;
};


ostream& operator << (ostream& out, Node * N);


#endif /* Node_h */
