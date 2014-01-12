#ifndef DICTIONNARY_H
#define DICTIONNARY_H
#include <string>
#include <set>
#include <string>
#include <fstream>
#include <iostream>


class Dictionnary
{
  
public:
  Dictionnary(const std::string&);
  Dictionnary(){};
  virtual ~Dictionnary();
  void generate(const std::string&);
  void addWord(std::string);
  bool isValid(const std::string&) const;
  std::set<std::string>::const_iterator getLowerBound(const std::string&) const;


private:
  std::set<std::string> dictionnary;

};
  


#endif // DICTIONNARY_H
