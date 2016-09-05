//
//  main.cpp
//  Node
//
//  Created by Joseph Mulray on 8/30/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//

#include <string>
#include <vector>
#include <fstream>
#include "Node.h"
#include <iostream>

int main(int argc, const char * argv[]) {

    Node N(3,NULL);
    Node *p = &N;
    
    Node pj;
    pj.Data(6);
    p->Data(5);
    cout<<p << endl;
    cout<<&pj<<endl;
    //*p = *(p->Next());
    
    
    vector<int> myInts;
    vector<int>::iterator itMyints;
    
    for(int x = 0; x <5 ; x++)
        myInts.push_back(x);
    
    itMyints = myInts.begin();
    
    for (itMyints; itMyints <myInts.end(); itMyints++){
        cout<<*itMyints << endl;
    }
    return 0;
}

