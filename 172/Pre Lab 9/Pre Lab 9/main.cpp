#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

int main(void)
{
    
    
    Node p = *new Node;
    Node N = *new Node;
    p.Next(&N);
    N.Next(new Node);
    
    N.Next()->Next(NULL);
    
    
    return 0;
}