#include "boggleSolver.h"

bool f (std::string i,std::string j) { return (i.size()>j.size()); }

BoggleSolver::BoggleSolver(const std::string& g)
{
  setGrid(g);
}

void BoggleSolver::setGrid(const std::string& g)
{
  std::vector<char> tmp;
  for(std::string::const_iterator it = g.begin(); it != g.end();++it)
  {
    if(*it != ' ')
    {
      if( *it != ',')
	tmp.push_back((char)toupper(*it));
      else
      {
	grid.push_back(tmp);
	tmp.clear();
      }
    }
  }
  grid.push_back(tmp);
  if(!checkGridIntegrity())
  {
      std::cerr << "Invalid Grid" << std::endl;
      resetGrid();
  }
}


std::vector< std::string > BoggleSolver::giveMeWords() const
{
  int x=0,y=0;
  std::set< std::string > result;
  std::set< std::string > otherResult;
  std::vector<std::string> res;
  for(std::vector<std::vector<char> >::const_iterator it = grid.begin(); it != grid.end();++it)
  {
    x=0;
    for(std::vector<char>::const_iterator itChar = (*it).begin(); itChar != (*it).end();++itChar)
    {
      Coordinates c = Coordinates(x,y);
      std::set< Coordinates > alreadyUsed;
      alreadyUsed.clear();
      
      otherResult =  giveMeWords("",c,alreadyUsed);
      result.insert( otherResult.begin(), otherResult.end() );
      x++;
    }
    y++;
  }
  
   res.insert( res.end(), result.begin(), result.end() );

  std::sort(res.begin(), res.end(),f);
  
  return res;
}

std::set< std::string > BoggleSolver::giveMeWords(std::string base, Coordinates start, std::set< Coordinates > alreadyUsed) const
{
  std::set< std::string > result;
  std::set< std::string > otherResult;
  base+=getLetter(start.getX(),start.getY());
  alreadyUsed.insert(start);
  if(base.size()>=MIN_WORD_LENGTH )
  {
    //Attention, upper != lower+1
    std::string upperBound = dictionnary.getUpperBound(base);

   if(dictionnary.isValid(base))
    result.insert(base);
    
   //Optimisation : si on ne trouve pas base dans le début de upper bound, on peut arreter
    if(upperBound.compare(0,base.size(),base)!=0)
      return result;

    
  }
  
  std::vector<Coordinates> adj = start.getAdjacent(gridSize-1,gridSize-1);
  for(std::vector<Coordinates >::const_iterator it = adj.begin(); it != adj.end();++it)
  {
    
      if(alreadyUsed.find(*it)==alreadyUsed.end())
      {
	otherResult = giveMeWords(base,*it,alreadyUsed);
	std::set_union(result.begin(), result.end(), otherResult.begin(), otherResult.end(), std::inserter(result,result.end()));

      }
   
  }
  return result;
}

char BoggleSolver::getLetter(int x, int y) const
{
  return grid.at(y).at(x);
}



bool BoggleSolver::checkGridIntegrity()
{
  int col = -1;
  gridSize = 0;
  for(std::vector<std::vector<char> >::const_iterator it = grid.begin(); it != grid.end();++it)
  {
    if(col==-1)
      col = (*it).size();
    else if((*it).size()!=col)
      return false;
      
  }
  if(col!=grid.size())
    return false;
  gridSize = col;
  return true;
}

void BoggleSolver::resetGrid()
{
  for(std::vector<std::vector<char> >::iterator it = grid.begin(); it != grid.end();++it)
  {
      (*it).clear();
  }
  grid.clear();
}


void BoggleSolver::displayGrid() const
{
  for(std::vector<std::vector<char> >::const_iterator it = grid.begin(); it != grid.end();++it)
  {
    for(std::vector<char>::const_iterator itChar = (*it).begin(); itChar != (*it).end();++itChar)
    {
      std::cout << *itChar << " ";
    }
    std::cout << std::endl;
  }
}

void BoggleSolver::setDictionnary(const Dictionnary& dico)
{
  dictionnary = dico;
}

