#include "Movie.h"
#include <string>
#include <cstdlib>
#include <ciso646>
#include <sstream>
#include <map>

using namespace std;


//constructor

Movie::Movie(){
    title_ = "" ;
    director_ = "";
    rating_ = Movie_Rating();
    year_ = 0;  
    url_ = "";
}
    
Movie::Movie(const string& title){
 
    title_ = title;
    director_ = "";
    rating_ = Movie_Rating();
    year_ = 0;
    url_ = "";
}

Movie::Movie(const string& title, const string& director,
    Movie_Rating rating, unsigned int year,const string& path)
{
    title_ = title;
    director_ = director;
    rating_ = rating;
    year_ = year;
    url_ = path;
}
//inspectors

string Movie::getTitle() const
{
    return title_;
}

string Movie::getDirector() const
{
    return director_;
}
Movie_Rating Movie::getRating() const
{
    return rating_;
}
unsigned int Movie::getYear() const
{
    return year_;
}
string Movie::getURL() const
{
    return url_;
}

//mutators

void Movie::setTitle(const string& title)
{
    title_ = title;
}
void Movie::setDirector(const string& director)
{
    director_ = director;
}

void Movie::setRating(Movie_Rating rating)
{
    rating_ = rating;
}

void Movie::setYear(unsigned int year)
{
    year_ = year;
}

void Movie::setURL(const string& path)
{
    url_ = path;
}

void Movie::output(ostream &out)
{
    
    map<int,string> rating;
    //int temp = getRating();
    string rating;
    
    rating = {0 = "G", 1 = "PG", 2 = "PG13", 3 = "R", 4 = "NC17", 5 = "NR"}
    
    string rate = rating.find(getRating);
    
    out << "Movie: "<<getTitle()<<endl;
    out <<"Director: "<<getDirector()<<endl;
    out<<"Year: "<< getYear()<<endl;
    out<<"Rating: "<<rate<<endl;
    out<<"URL: "<<getURL()<<endl;
    out<<endl;
}




