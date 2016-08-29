
//----------------------------------------------------------------------------
//
//----------------------------- DUPoint3D Tester -----------------------------
//
//----------------------------------------------------------------------------
//
//  Program Name: test DUPoint3D Driver
//
//  This program is designed to test class inheritance 
//  through the implementation of the DUPoint3D class as a derived class of
//  the DUPoint class.
// 
//  Author:         JL Popyack
//  Course:         CS172
//  Date:           5/21/99
//
//  Modified:       P Zoski (pzoski@mcs.drexel.edu)
//                  changed output formatting to suit VC++
//  Modified:       JL Popyack: 5/18/2
//                  reformatted
//
//----------------------------------------------------------------------------


	#include <iostream>
	#include <vector>
	#include "DUPoint3D.h" 
    #include "DUPoint.h"
    #include "DUPolygon.h"
	using namespace std ;


//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{
	//----------------------------------------------------------------------------
	//	Test DUPoint3D creation and output.
	//----------------------------------------------------------------------------

		cout << "Testing the DUPoint3D Class" << endl << endl ;

		DUPoint   p1(1,2), p2(4,5), p3(6,5), p4(-5,-1);
		DUPoint3D q1(6,0,9), q2(3,0,2), q3(2,1,5), q4(8,9,5);
		DUPoint3D q5(q3) ;
	
		cout << "The following DUPoint objects have been declared in main():" << endl 
		     << "  p1=" << p1 << "\tp2=" << p2 << endl
		     << "  p3=" << p3 << "\tp4=" << p4
		     << endl << endl ;
	    
		cout << "The following DUPoint3D objects have been declared in main():" << endl 
		     << "  q1=" << q1 << "\tq2=" << q2 << endl
		     << "  q3=" << q3 << "\tq4=" << q4 << endl 
		     << "  q5=" << q5
		     << endl << endl ;
	
	//----------------------------------------------------------------------------
	//	Create a vector of DUPoint objects
	//----------------------------------------------------------------------------
	    
		vector<DUPoint *> v ;
        DUPoint *ptr1 = &p1;
        DUPoint *ptr2 = &q2;
        DUPoint *ptr3 = &q3;
        DUPoint *ptr4 = &p4;
		v.push_back(ptr1);
		v.push_back(ptr2) ;
		v.push_back(ptr3) ;
		v.push_back(ptr4) ;

		cout << "There are " << v.size() << " points in this list:" << endl ;
		int i ;
		for(i=0; i<v.size(); i++)
            cout << "  DuPoint #" << i << ": " << *v[i] << endl ;
		cout << endl ;
		
	//----------------------------------------------------------------------------
	//	Create a vector of DUPoint3D objects.
	//----------------------------------------------------------------------------

		vector<DUPoint3D> w ;
		w.push_back(q1) ;
		w.push_back(q2) ;
		w.push_back(q3) ;
		w.push_back(q4) ;
		w.push_back(q5) ;

		cout << "There are " << w.size() << " points in this list:" << endl ;
		for(i=0; i<w.size(); i++)
		   cout << "  DuPoint3D #" << i << ": " << w[i] << endl ;
		cout << endl ;

		return 0 ;
	}