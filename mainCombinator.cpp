#include "combinator.h"
#include <algorithm>  
#include <cstring>
#include "boggleSolver.h"
#include "util.h"



void usage()
{
 std::cout << "Combinator permet de trouver les mots qu'il est possible de former a partir d'un ensemble de lettre" << std::endl;
 std::cout << "Arguments : " << std::endl;
 std::cout << "\t --d <filepath>. Dictionnaire utilise" << std::endl;
 std::cout << "\t\t Mode combinatoire : " << std::endl;
 std::cout << "\t\t\t --ls <str>. Combine les lettres de \"str\" pour determiner les mots qu'il est possible de former a partir de ces lettres" << std::endl;
 std::cout << "\t\t\t -a. (optionnel) Trouve uniquement les mots qui sont des anagrammes de l'ensemble de lettres fournie." << std::endl;
 std::cout << "\t\t\t -sl. (optionnel) Tri le resultat par taille de mots decroissante" << std::endl;
 std::cout << "\t\t Mode vérification de mots : " << std::endl;
 std::cout << "\t\t\t --w <wordList>. Format de wodList : mot1,mot2,... Pour chaque mot, vérification de sa validite" << std::endl;
 exit(1);
}

int main(int argc, char **argv) {
    
    std::string dictionnary;
    std::string letterset;
    std::string wl;
    bool anagram = false;
    bool sortByLength = false;
    int i=1;
    while(i<argc)
    {
	if(strcmp(argv[i],"--d")==0)
	{
	  
	    if(i+1<argc)
	    {
	      dictionnary = argv[i+1];
	      i++;
	    }
	    else
	      usage();
	}
	else if(strcmp(argv[i],"--ls")==0)
	{
	    if(i+1<argc)
	    {
	      letterset = argv[i+1];
	      i++;
	    }
	    else
	      usage();
	}
	else if(strcmp(argv[i],"--w")==0)
	{
	    if(i+1<argc)
	    {
	      wl = argv[i+1];
	      i++;
	    }
	    else
	      usage();
	}
	else if(strcmp(argv[i],"-a")==0)
	{
	   anagram = true;
	}
	else if(strcmp(argv[i],"-sl")==0)
	{
	   sortByLength = true;
	}
	else
	{
	  usage();
	}
	i++;
      
    }
    if(dictionnary.empty() || (!wl.empty() && (!letterset.empty() || sortByLength || anagram ) ) || (wl.empty() && letterset.empty()) )
      usage();
    Dictionnary d =  Dictionnary(dictionnary);
    Combinator c = Combinator();
    
    c.setDictionnary(d);
    
    if(!wl.empty())
    {
      std::vector<std::string> words = split(wl,',');
      std::cout << "-------------------------------------------------------------------------------" << std::endl;
      std::cout << "Test des mots suivants " << wl << std::endl;
      for(std::vector<std::string>::iterator it = words.begin(); it != words.end();++it)
      {
	if(d.isValid(*it))
	  std::cout << *it << " : OK " << std::endl;
	else
	  std::cout << *it << " : KO " << std::endl;
	
      }
      
       std::cout << "-------------------------------------------------------------------------------" << std::endl; 
    }
    else
    {
    
      c.setLetterSet(letterset);
      c.setAnagramMode(anagram);
      std::vector<std::string> res = c.giveMeWords();
      std::cout << "-------------------------------------------------------------------------------" << std::endl; 
      std::cout << "Avec le dictionnaire sélectionné, et les lettres " << c.getLetterSet() << std::endl;
      std::cout << "Il est possible de former les mots suivants :" << std::endl;
      if(sortByLength)
	std::sort(res.begin(), res.end(),sortFunction);
      else
	std::sort(res.begin(), res.end());
      for(std::vector<std::string>::iterator it = res.begin(); it != res.end();++it)
      {
	std::cout << *it << std::endl; 
      }
      std::cout << "-------------------------------------------------------------------------------" << std::endl; 
    }
   
    return 0;
}


