#include <iostream>
#include <string>
#include <vector>
#include "Actor.h"


using namespace std;

Actor::Actor(){
    
    movies_.clear();
    numMovies_ = 0;
    actorName_.clear();
}

void Actor::addMovie(string movie, string name){
    
    numMovies_++;
    movies_ = movie;
    actorName_ = name;
    
  }

void Actor::output(ostream &out) {

    
    for (int x = 0; x < movies_.size() ; x++){
        
        out << movies_[x] << endl;
        
    }
}
string Actor::getName(){
    
    return actorName_;
}
string const Actor::getMovies(){
    return movies_;
}

