#ifndef BOGGLESOLVER_H
#define BOGGLESOLVER_H
#include "dictionnary.h"
#include "coordinates.h"
#include <vector>
#include <set>
#include <algorithm>


class BoggleSolver
{
public :
  BoggleSolver(const std::string&);
  BoggleSolver(){};
  void setGrid(const std::string&);
  //Utilisation d'un vector et pas un set, pour sort
  std::vector<std::string> giveMeWords() const;
  void displayGrid() const;
  void setDictionnary(const Dictionnary&);
  void resetGrid();
  char getLetter(int,int) const;

  
private :
  static const int MIN_WORD_LENGTH = 3;
  std::set<std::string> giveMeWords(std::string base, Coordinates start, std::set< Coordinates > alreadyUsed) const;
  
  bool checkGridIntegrity();
  std::vector<std::vector<char> > grid;
  Dictionnary dictionnary;
  int gridSize;
};

#endif // BOGGLESOLVER_H
