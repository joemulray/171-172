#include <iostream>
#include <string>
#include <fstream>
#include "Movie.h"
#include <cstdlib>
using namespace std;


void promptForMovie(Movie & myMovie);



int main(void)
{
    
    
    ofstream fout ("MOVIE.txt");        //pass fout as ostream for output 
    Movie movie1;
    movie1.setTitle("Harold and Maude");
    movie1.setDirector("Hal Ashby");
    movie1.setYear(1971);
    movie1.setRating(R);
    movie1.setURL("http://www.imdb.com/title/tt0067185/");
    movie1.output(cout);
    movie1.output(fout);
    
    
    Movie movie2;
    Movie movie3;
    Movie movie4;
    Movie movie5;
    
    promptForMovie(movie2);
    promptForMovie(movie3);
    promptForMovie(movie4);
    promptForMovie(movie5);
    
    
    movie2.output(cout);
    movie2.output(fout);
    
    
    movie3.output(cout);
    movie3.output(fout);

    
    movie4.output(cout);
    movie4.output(fout);
    
    
    movie5.output(cout);
    movie5.output(fout);


    
    fout.close();
}







void promptForMovie(Movie & myMovie)
{
    string title;
    string director;
    string userrating;
    unsigned int year;
    string  url ;
    int rating;
    
    cout<<endl;
    
    cout << "Movie: ";
    getline(cin,title);
    
    cout<<"Director: ";
    getline(cin,director);
    
    cout<<"Rating: ";
    getline(cin,userrating);            //Get user input and send back value of Movie_Rating
    
    if (userrating == "G")
    {
        rating = G;
    }
    else if (userrating == "PG")
    {
        rating =PG;
    }
    else if (userrating == "PG13")
    {
        rating = PG13;
    }
    else if (userrating == "R")
    {
        rating= R;
    }
    else if (userrating == "NC17")
    {
        rating=NC17;
    }
    else if (userrating == "NR")
    {
        rating= NR;
    }
    else            //default to g rating
    {
        rating= G;
    }
    
    cout<<"IMDB URL: ";
    getline(cin,url);
    
    cout<<"Year: ";
    cin>>year;
    cin.ignore();   
    
    
     myMovie = Movie(title,director,Movie_Rating(rating),year,url);
    
}