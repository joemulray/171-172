//----------------------------------------------------------------------------
//
//-------------------------- DUPoint*, DULine* Tester ------------------------
//
//----------------------------------------------------------------------------
//
//  Program Name: testDriver cpp
//
//  This program investigates pointer concepts through the DUPoint and DULine 
//  classes.
//
//  Author:         JL Popyack
//  Course:         CS172
//  Date:           5/13/98
//
//  Modified:       JL Popyack: 5/8/2
//
//
//----------------------------------------------------------------------------

	#include <iostream>
	#include <string>
	#include "DUPoint.h"
	#include "DULine.h"
    #include <vector>
	using namespace std ;


//----------------------------------------------------------------------------
//
//-------------------------------- Prototypes --------------------------------
//
//----------------------------------------------------------------------------

	int  min_value  ( int &a, int &b ) ;
	int& min_element( int &a, int &b ) ;
	
//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{

		int i = 5, k = 7;
	
	//----------------------------------------------------------------------------
	// iPtr is a variable that can point to an integer
	//----------------------------------------------------------------------------
		int * iPtr ;
					
	//----------------------------------------------------------------------------
	// iPtr is assigned the address of i
	// iPtr now "points at" i
	//----------------------------------------------------------------------------
		iPtr = &i ;
	
	//----------------------------------------------------------------------------
	// Printing iPtr reveals the address of i
	//----------------------------------------------------------------------------
		cout << "iPtr=" << iPtr << endl ;
	
	//----------------------------------------------------------------------------
	// The object pointed at by iPtr may be referenced
	// as *iPtr
	//----------------------------------------------------------------------------
		cout << "*iPtr=" << *iPtr << endl ;
		cout << "i=" << i << endl ;
	
	//----------------------------------------------------------------------------
	// jPtr is another 'integer pointer' variable
	//----------------------------------------------------------------------------
		int * jPtr ;
	
	//----------------------------------------------------------------------------
	// jPtr is assigned the value of iPtr
	// jPtr now holds the same address that iPtr holds
	//----------------------------------------------------------------------------
		jPtr = iPtr ;
		cout << "jPtr=" << jPtr << endl ;
	
        DUPoint p(3,8);
    
        DUPoint * pPtr;
        pPtr = new DUPoint(3,8) ;
        
        cout<<"(*pPtr).getX() = "<< (*pPtr).getX()<<endl;
        cout<<"(*pPtr).getY() = "<< (*pPtr).getY()<<endl;
        
        int x = (*pPtr).getX();
        int y = (*pPtr).getY();
        (*pPtr).setX(y);
        (*pPtr).setY(x);
        
        cout<<"*pPtr = "<< *pPtr<<endl;
        
        
        
        DULine L(p, *pPtr) ;
        cout << L << endl ;
        
        
        DUPoint *qPtr = new DUPoint(2,7);
        
        cout<<*qPtr<<endl;
        
        qPtr = &p;
        
        cout<<*qPtr<<endl;
        
        cout<<(*qPtr).getY()<<endl;
        
        
        
        vector<DUPoint *> Triangle(3);
        Triangle[0] = new DUPoint(3,4);
        Triangle[1] = new DUPoint(5,9);
        Triangle[2] = new DUPoint(7,1);
        
        for(int x = 0; x>Triangle.size(); x++)
        {
            int a,b;
            cout<<"Please enter an X Point: "<<endl;
            cin>>a;
            cout<<"Please enter an Y Point: "<<endl;
            cin>>b;
            Triangle[x] = new DUPoint(a,b);
            
        }
        
        for(int x = 0; x < Triangle.size();x++)
        {
            cout<<*Triangle[x]<<endl;
        }
        
        
        
        
        cout<<min_value(k, i)<<endl;
        cout<<min_element(i,k)<<endl;
        
        
        min_element(i,k)=0 ;
	    return 0;
        
	}


//----------------------------------------------------------------------------
//
//-------------------------- Subprogram Definitions --------------------------
//
//----------------------------------------------------------------------------

	int  min_value  ( int &a, int &b )
	{
		if( a < b )
			return a ;
		else
			return b ;
	}
	
//----------------------------------------------------------------------------
//
	int& min_element( int &a, int &b )
	{
		if( a < b )
			return a ;
		else
			return b ;
	}