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
    string tempActor, tempYear,tempRating;
    int year;
    Movie_Rating rating;
    
    ifstream file;
    file.open("data.txt");
    
    vector<string> actor;
    vector<Movie> movie_vector;
    
    while (!file.eof( ))
    {
        
        getline(file,title);
        getline(file,director);
        getline(file,tempYear);
        getline(file,tempRating);
        getline(file,url);


        year = atoi(tempYear.c_str());
        
        
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
        
        
        
        while (getline(file, tempActor) && tempActor != "$$$$")
        {
            actor.push_back(tempActor);
        }

        movie_vector.push_back(Movie(title, director, rating, year, url, actor));
        actor.resize(0);
        
    }
    
    //Print movie objects.
    for (int x=0;x<movie_vector.size();x++)
    {
        Movie fileMovie = movie_vector[x];
        fileMovie.output(cout);
        if(x != movie_vector.size()-1)
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