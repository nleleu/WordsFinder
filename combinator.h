#ifndef COMBINATOR_H
#define COMBINATOR_H
#include "dictionnary.h"
#include <vector>
  

class Combinator
{
public: 
  Combinator(std::string&);
  Combinator(){setAnagramMode(false);};
  virtual ~Combinator();
  void setLetterSet(std::string);
   //Utilisation d'un vector et pas un set, pour sort
  std::vector<std::string> giveMeWords();
  void setDictionnary(const Dictionnary&);
  std::string getLetterSet() const;
  void setAnagramMode(bool);
private:
  
  std::vector<std::string> giveMeWords(std::string begin,std::vector<char> letterSet);
  std::vector<char> letterSet;
  std::vector<std::string> result;
  Dictionnary dictionnary;
  std::set<std::string> alreadyTested;
  bool anagramMode;
  
};

#endif // COMBINATOR_H
