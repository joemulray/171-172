//
//  Actor.hpp
//  Homework 4
//
//  Created by Joseph Mulray on 8/25/16.
//  Copyright © 2016 Joseph Mulray. All rights reserved.
//

#ifndef Actor_h
#define Actor_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "Movie.h"

using namespace std;


class Actor

{
public:
    
    //------------------------------------------------------
    //----- Constructors -----------------------------------
    //------------------------------------------------------
    Actor();
    
    //------------------------------------------------------
    //----- Destructor -------------------------------------
    //------------------------------------------------------
    
	  	
    //------------------------------------------------------
    //----- Inspectors -------------------------------------
    //------------------------------------------------------
    string const getMovies();
    string getName();
    
    //------------------------------------------------------
    //----- Mutators ---------------------------------------
    //------------------------------------------------------
    
    void addMovie(string movie, string name);
    
    //------------------------------------------------------
    //----- Facilitators -----------------------------------
    //------------------------------------------------------
    
    //------------------------------------------------------
    // insert DUPolygon in output stream
    void output(ostream& out) ;
    
private:
    string movies_;
    int numMovies_;
    string actorName_;
    
    
    
};


//----------------------------------------------------------------------------
//----- DUPolygon: auxiliary operator descriptions ---------------------------
//----------------------------------------------------------------------------

ostream& operator<< (ostream& out, const Actor &actor) ;



#endif /* Actor_h */
