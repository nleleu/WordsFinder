#include "dictionnary.h"


Dictionnary::Dictionnary(const std::string& dicoFile)
{
  generate(dicoFile);
}

void Dictionnary::generate(const std::string& dicoFile)
{
  std::ifstream file(dicoFile.c_str());  
  int i = 1;
        if(file)  
        {
	  
	  while(!file.eof())
	  {
	    std::string word;
	    file >> word;
	    if(!word.empty())
	    {
	      addWord(toUpper(word));
	    }
	  }
	  file.close(); 
        }
        else 
	  std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

bool Dictionnary::isValid(const std::string& word) const
{

    return dictionnary.find(toUpper(word))!=dictionnary.end();
  
}




std::string Dictionnary::getUpperBound(const std::string& word) const
{
  std::string res;
  std::set<std::string>::const_iterator upper = dictionnary.upper_bound(toUpper(word));
  if(upper!=dictionnary.end())
    res = *upper;
  return res;
  
}




std::string Dictionnary::toUpper(const std::string& word) const
{
  std::string tmp;
  tmp.resize(word.size());
  std::transform(word.begin(), word.end(), tmp.begin(), ::toupper);
  return tmp;
}




void Dictionnary::addWord(std::string word)
{
  dictionnary.insert(word);
  

}

Dictionnary::~Dictionnary()
{

}



