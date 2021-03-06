#ifndef DICTIONNARY_H
#define DICTIONNARY_H
#include <string>
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm> 


class Dictionnary
{
  
public:
  Dictionnary(const std::string&);
  Dictionnary(){};
  virtual ~Dictionnary();
  void generate(const std::string&);
  void addWord(std::string);
  bool isValid(const std::string&) const;
  std::string getUpperBound(const std::string&) const;

private:
  std::set<std::string> dictionnary;
  std::string toUpper(const std::string& )const;

};
  


#endif // DICTIONNARY_H
