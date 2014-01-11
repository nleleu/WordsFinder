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
	    if(word.size()>0)
	    {
	      addWord(word);
	    }
	  }
	  file.close(); 
        }
        else 
	  std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

bool Dictionnary::isValid(const std::string& word) const
{

    return dictionnary.find(word)!=dictionnary.end();

   
  
  
}

void Dictionnary::addWord(std::string word)
{
  dictionnary.insert(word);
  

}

Dictionnary::~Dictionnary()
{

}


