#include <iostream>
#include <string>
#include <fstream>
#include "Movie.h"
#include <cstdlib>
using namespace std;


void promptForMovie(Movie & myMovie);


int main(void)
{
    
    string title, director, url;
    string actor, tempYear,tempRating;
    int year;
    Movie_Rating rating;
    
    ifstream file;
    file.open("data.txt");
    
    
    
    while (!file.eof( ))
    {
        
        Movie fileMovie;
        getline(file,title);
        getline(file,director);
        getline(file,tempYear);
        getline(file,tempRating);
        getline(file,url);
        getline(file,actor);

        year = stoi(tempYear);
        fileMovie.setTitle(title);
        fileMovie.setDirector(director);
        fileMovie.setYear(year);
        
        if (tempRating == "G")
            rating = G;
        else if (tempRating == "PG")
            rating =PG;
        else if (tempRating == "PG13")
            rating = PG13;
        else if (tempRating == "R")
            rating= R;
        else if (tempRating == "NC17")
            rating=NC17;
        else if (tempRating == "NR")
            rating= NR;
        else            //default to g rating
            rating= G;
        
        fileMovie.setRating(rating);
        fileMovie.setURL(url);
        
        while (actor!="$$$$")
        {
            fileMovie.setActor(actor);
            getline(file,actor);
        }

        fileMovie.output(cout);
        cout<<"\n";
    }
    file.close();
    
}


void promptForMovie(Movie & myMovie)
{
    string title;
    string director;
    string tempRating;
    unsigned int year;
    string  url ;
    int rating;
    vector<string> actor;
    cout<<endl;
    
    cout << "Movie: ";
    getline(cin,title);
    
    cout<<"Director: ";
    getline(cin,director);
    
    cout<<"Rating: ";
    getline(cin,tempRating);            //Get user input and send back value of Movie_Rating
    
    if (tempRating == "G")
        rating = G;
    else if (tempRating == "PG")
        rating =PG;
    else if (tempRating == "PG13")
        rating = PG13;
    else if (tempRating == "R")
        rating= R;
    else if (tempRating == "NC17")
        rating=NC17;
    else if (tempRating == "NR")
        rating= NR;
    else            //default to g rating
        rating= G;
    cout<<"Year: ";
    cin>>year;
    cin.ignore();
    
    
    cout<<"IMDB URL: ";
    getline(cin,url);
    
    
    
     myMovie = Movie(title,director,Movie_Rating(rating),year,url,actor);
    
}