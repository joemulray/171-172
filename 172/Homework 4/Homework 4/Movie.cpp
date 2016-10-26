#include "Movie.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


//constructor

Movie::Movie(){
    title_ = "" ;
    director_ = "";
    rating_ = Movie_Rating();
    year_ = 0;  
    url_ = "";
}
//default constructor for string and title.
Movie::Movie(const string& title){
 
    title_ = title;
    director_ = "";
    rating_ = Movie_Rating();
    year_ = 0;
    url_ = "";
    actor_.push_back("");
}

Movie::Movie(const string& title, const string& director,
    Movie_Rating rating, unsigned int year,const string& path, vector<string> actor)
{
    title_ = title;
    director_ = director;
    rating_ = rating;
    year_ = year;
    url_ = path;
    actor_ = actor;
}
//Destructor
Movie::~Movie()
{
    title_.clear();
    director_.clear();
    rating_ = Movie_Rating();
    year_ = NULL;
    url_.clear();
    actor_.clear();
    ;
}

//copy construtor
Movie::Movie(Movie const &movie)
{
    title_ = movie.title_;
    director_ = movie.director_;
    rating_ = movie.rating_;
    year_ = movie.year_;
    url_ = movie.url_;
    actor_ = movie.actor_;
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
vector<string> Movie::getActor() const
{
    return actor_;
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
void Movie::setActor(const string actor)
{
    actor_.push_back(actor);
    sort( actor_.begin(), actor_.end() );
}

void Movie::output(ostream &out)
{
    int temp = getRating();
    string rating;
    
    if (temp==0)
        rating = "G";
    else if (temp==1)
        rating ="PG";
    else if (temp==2)
        rating ="PG13";
    else if (temp==3)
        rating ="R";
    else if (temp==4)
        rating ="NC17";
    else
        rating ="NR";

    
    
    
    //out << "Movie: "<<getTitle()<<endl;
    
    out << getDirector()<<endl;
    out<< getYear()<<endl;
    out<< rating<<endl;
    out<< getURL()<<endl;
    
    //out<<"Actors:"<<endl;
    
    for( int x = 0 ; x< getActor().size();x++)
    {
        out<< getActor()[x]<<endl;
    }
}

