//
// Created by Ross Allen on 4/7/17.
//

#ifndef FILMMAINHW12_FILMSTATS_H
#define FILMMAINHW12_FILMSTATS_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Film{
  string title;
  double worldWideGross;
  int releaseYear;
};

class FilmStats {

public:
  bool processFile(string file);
  Film getFilmByRank(int rank);
  double getTotalOfFilms(int startRank, int endRank);
  double getAverageOfFilms(int startRank, int endRank);

private:
  static const int NUM_FILMS = 50;
  Film stats[NUM_FILMS];

};


#endif //FILMMAINHW12_FILMSTATS_H
