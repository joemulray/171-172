#ifndef __Movie_h__
#define __Movie_h__

#include <string>
#include <vector>
using namespace std;


enum Movie_Rating {G,PG,PG13,R,NC17,NR};


class Movie
{
    
    
public: // interface of the Socialite_user class
    
    //------------ Constructors ------------------
    
    Movie();
    Movie(const string& title) ;
    Movie(const string& title,
          const string& director,
          Movie_Rating rating,
          unsigned int year,
          const string& path, vector<string> actor) ;
    Movie(Movie const &movie);
    
    // ------------------------------------------------------
    // ----- Destructor -------------------------------------
    // ------------------------------------------------------
    
    	~Movie();  // To be implemented in a future assignment.
	  	
    //------------ Inspectors --------------------
	  	
    string getTitle() const ;
    string getDirector() const ;
    Movie_Rating getRating() const ;
    unsigned int getYear() const ;
    string getURL() const ;
    vector<string> getActor() const;
	  	
    //------------ Mutators ---------------------
    
    void setTitle(const string& title);
    void setDirector(const string& director) ;
    void setRating(Movie_Rating rating)  ;
    void setYear(unsigned int year)  ;
    void setURL(const string& path)  ;
    void setActor(vector<string> actor);
    void output(ostream & cout);
    
    
private: // private data fields associated with Socialite_user objects
    // Underscores indicate a private member variable
    
    string title_ ;
    string director_ ;
    Movie_Rating rating_;
    unsigned int year_ ;
    string  url_ ;
    vector<string> actor_;
    
};


#endif