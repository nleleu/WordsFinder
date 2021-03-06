#include "combinator.h"



Combinator::Combinator(std::string& ls)
{
  setAnagramMode(false);
  setLetterSet(ls);
}

void Combinator::setLetterSet(std::string ls)
{
  letterSet.clear();
  for(std::string::iterator it = ls.begin(); it != ls.end();++it)
  {
     
     if( *it != ' ')
       letterSet.push_back((char)toupper(*it));
  }
}

void Combinator::setAnagramMode(bool val)
{
  anagramMode = val;
}


void Combinator::setDictionnary(const Dictionnary& dico)
{
  dictionnary = dico;
}

std::vector<std::string> Combinator::giveMeWords()
{
  alreadyTested.clear();
  return giveMeWords("",letterSet);
  alreadyTested.clear();

}


std::vector<std::string> Combinator::giveMeWords(std::string begin,std::vector<char> ls)
{
  std::vector<std::string> result;
  
  
  std::vector<char> otherLetters = ls;
  int pos = 0;
  for(std::vector<char>::iterator it = ls.begin(); it != ls.end();++it)
  {
    std::vector<std::string> otherResult;
    std::string source = begin;
    std::vector<char> otherLetters = ls;
    source += *it;
    otherLetters.erase(otherLetters.begin()+pos);
    if(alreadyTested.find(source)==alreadyTested.end())
    {
      alreadyTested.insert(source);
      
      //Attention, upper != lower+1
      std::string upperBound = dictionnary.getUpperBound(source);
      if(!anagramMode || (anagramMode && source.size() == letterSet.size()))
      {
	 if(dictionnary.isValid(source))
	  result.push_back(source);
	  
      }
      //Optimisation : si on ne trouve pas source dans le début de upper bound, on peut arreter
	 if(upperBound.compare(0,source.size(),source)==0)
	    otherResult = giveMeWords(source,otherLetters);

	
	
	 
	
	result.insert( result.end(), otherResult.begin(), otherResult.end() );
    }
   
     pos ++ ;
    
  }
  return result;

}

std::string Combinator::getLetterSet() const 
{
  std::string res;
  for(std::vector<char>::const_iterator it = letterSet.begin(); it != letterSet.end();++it)
  {
    res+=*it;
    if(it+1!=letterSet.end())
      res+=",";
    
  }
  return res;
}


Combinator::~Combinator()
{

}



