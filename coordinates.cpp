#include "coordinates.h"

Coordinates::Coordinates(int _x, int _y)
{
  x=_x;
  y=_y;
}

void Coordinates::display() const
{
  std::cout << "X : " << x << ", Y : " << y << std::endl; 
}


std::vector< Coordinates> Coordinates::getAdjacent(int boundX, int boundY) const
{
  std::vector< Coordinates> res;
  //Haut
  if(y>=1)
  {
    Coordinates tmp = Coordinates(x,y-1);
    res.push_back(tmp); 
  }
  
  //Bas
  if(y+1<=boundY)
  {
    Coordinates tmp = Coordinates(x,y+1);
    res.push_back(tmp); 
  }
    
   //Gauche
   if(x>=1)
   {
    Coordinates tmp = Coordinates(x-1,y);
    res.push_back(tmp); 
   }
   
   //Droite
   if(x+1<=boundX)
   {
    Coordinates tmp = Coordinates(x+1,y);
    res.push_back(tmp); 
   }
   
   //Diag Gauche Sup
    if(x>=1 && y>=1)
   {
    Coordinates tmp = Coordinates(x-1,y-1);
    res.push_back(tmp); 
   }
   
   //Diag Gauche Inf
    if(x>=1 && y+1<=boundY)
   {
    Coordinates tmp = Coordinates(x-1,y+1);
    res.push_back(tmp); 
   }
   
    //Diag Droite Sup
    if(x+1<=boundX && y>=1)
   {
    Coordinates tmp = Coordinates(x+1,y-1);
    res.push_back(tmp); 
   }
   
    //Diag Droite Inf
    if(x+1<=boundX && y+1<=boundY)
   {
    Coordinates tmp = Coordinates(x+1,y+1);
    res.push_back(tmp); 
   }
   return res;
}


bool Coordinates::operator<(const Coordinates& c) const
{
  return getX()<c.getX() || (getX()==c.getX() && getY()<c.getY());
}

bool Coordinates::operator==(const Coordinates& c) const
{
  return c.getX()==getX() && c.getY()==getY(); 
}

