//
// Created by Ross Allen on 4/7/17.
//

#include "FilmStats.h"

bool FilmStats::processFile(string file){
  ifstream fin;
  fin.open(file);
  if(!fin.is_open()){
    return false;
  }else{
    for(int i = 0; i < NUM_FILMS; i++){
      Film movie;
      getline(fin, movie.title, '#' );
      fin >> movie.worldWideGross;
      fin >> movie.releaseYear;
      fin.ignore();
      stats[i] = movie;
    }
    return true;
  }
}

Film FilmStats::getFilmByRank(int rank){
  if(rank < 1 || rank > 50){
    Film invalidMovie;
    invalidMovie.title = "Invalid";
    invalidMovie.worldWideGross = 0.0;
    invalidMovie.releaseYear = 0;
    return invalidMovie;
  }
  return stats[rank - 1];
}

double FilmStats::getTotalOfFilms(int startRank, int endRank){
  double total = 0;
  if(startRank <= 0){
    startRank = 1;
  }
  if(endRank >= 50){
    endRank = 50;
  }
  for(int i = (startRank-1); i < (endRank); i++){
    total += stats[i].worldWideGross;
  }
  return total;
}

double FilmStats::getAverageOfFilms(int startRank, int endRank){
  if(startRank <= 0){
    startRank = 1;
  }
  if(endRank >= 50){
    endRank = 50;
  }

  double average = getTotalOfFilms(startRank, endRank);
  return average/(endRank - (startRank-1));
  }




// cin.ignore(' '); argument inside.
// example: cout << "age: ";
//cin >> age;
//cin.ignore(argument);
// stats[i].worldWideGross.