#ifndef COORDINATES_H
#define COORDINATES_H
#include <iostream>
#include <vector>

class Coordinates
{
public:
  Coordinates(int,int);
  std::vector<Coordinates> getAdjacent(int boundX, int boundY) const;
  void display() const;
  int getX() const {return x;};
  int getY() const {return y;};
  bool operator<(const Coordinates& c) const;
  bool operator==(const Coordinates& c) const;
private:
  int x;
  int y;
};

#endif // COORDINATES_H
