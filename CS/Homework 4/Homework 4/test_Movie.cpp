#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Movie.h"
#include "Actor.h"
#include <list>

using namespace std;


//Prototypes

void promptAnswer(vector<Movie*> MovieVector);
int listActors(vector<Movie*> MovieVector);
void listMovies(vector<Actor*> ActorVector);
int movieInfo(vector<Movie*> MovieVector);
void promptAnswer(vector<Movie*> MovieVector, vector<Actor*> ActorVector);


int main(void)
{
    
    string title, director, url;
    string actor, tempYear,tempRating;
    int year;
    Movie_Rating rating;
    
    ifstream file;
    file.open("data.txt");
    

   	vector<Movie*> MovieVector;
    vector<Actor*> ActorVector;
    
    while (!file.eof( ))
    {
        
        
        getline(file,title);
        getline(file,director);
        getline(file,tempYear);
        getline(file,tempRating);
        getline(file,url);
        getline(file,actor);
        
        
        Movie* fileMovie = new Movie();
        
        year = stoi(tempYear);
        fileMovie->setTitle(title);
        fileMovie->setDirector(director);
        fileMovie->setYear(year);
    
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
        
        fileMovie->setRating(rating);
        fileMovie->setURL(url);

        
        
        while (actor!="$$$$")
        {
            Actor* fileActor = new Actor();
            fileActor->addMovie(title, actor);
            fileMovie->setActor(actor);
            ActorVector.push_back(fileActor);
            getline(file,actor);
        }
        
    
        MovieVector.push_back(fileMovie);
    
    }
    file.close();

  promptAnswer(MovieVector, ActorVector);
    
}


void promptAnswer(vector<Movie*> MovieVector, vector<Actor*> ActorVector)
{
    
    int options;
    string input;
    int vectorPt = -1;
    
    cout<<"Choose from the following options:"<<endl;
    cout<< "1. List Actors by Movie" <<endl;
    cout<< "2. List Movies by Actor" <<endl;
    cout<< "3. Info by Movie" <<endl;
    cout<< "4. Extra Credit A: List Movies by Director" <<endl;
    cout<< "5. Extra Credit C: List Movies by Director/Actor" <<endl;
    cout<< "6. Extra Credit D: Degrees of Separation" <<endl;
    cout<< "Enter choice: ";
    
    cin>>options;
    cin.ignore();
    
    
    if(options == 1){
        vectorPt = listActors(MovieVector);
        
        
        while (vectorPt == -1)
        {
            cout<< "Search not found:" << endl;
            cout<< "Enter a movie name: ";
            getline(cin,input);
            vectorPt = listActors(MovieVector);
            
        }
        
        for( int z = 0 ; z < MovieVector[vectorPt]->getActor().size(); z++ )
        {
            cout<< MovieVector[vectorPt]->getActor()[z] << endl;
        }
        
        
    }
    else if (options == 2){
        
       listMovies(ActorVector);
        
    }
    else if (options == 3){
        
        vectorPt = movieInfo(MovieVector);
        
        while (vectorPt == -1)
        {
            cout<< "Search not found:" << endl;
            vectorPt = listActors(MovieVector);
        }
        
        MovieVector[vectorPt]->output(cout);
        
    }
    
}

int listActors(vector<Movie*> MovieVector)
{
    string input;
    
    cout<< "Enter a movie name: ";
    getline(cin,input);
    
    for( int x = 0; x < MovieVector.size(); x++){
        if (MovieVector[x]->getTitle() == input){
            return x;
        }
    }
    return -1;
    

}
void listMovies(vector<Actor*> ActorVector)
{
    string input;
    
    
    cout<< "Enter a movie name: ";
    getline(cin,input);
    vector<string> movieAppearace;
    
    for(int x = 0; x < ActorVector.size(); x++)
    {
        if(ActorVector[x]->getName() == input)
        {
            string movieName = ActorVector[x]->getMovies();
            if (find(movieAppearace.begin(), movieAppearace.end(), movieName) == movieAppearace.end())
            {
                movieAppearace.push_back(movieName);
                sort( movieAppearace.begin(), movieAppearace.end() );
            }
        }
        
    }
    if(movieAppearace.size() == 0)
    {
        cout << "Invalid actor name:" << endl;
        listMovies(ActorVector);
    }
    else{
        
        for(int z = 0; z < movieAppearace.size(); z++)
        {
        cout<<movieAppearace[z]<<endl;
        }
    }
}

int movieInfo(vector<Movie*> MovieVector)
{
    string input;
    
    cout<< "Enter a movie name: ";
    getline(cin,input);
    
    for( int x = 0; x < MovieVector.size(); x++){
        if (MovieVector[x]->getTitle() == input){
            return x;
        }
    }
    return -1;
    
}

