#include <algorithm>  
#include <cstring>
#include "combinator.h"
#include "boggleSolver.h"

bool sortFunction (std::string i,std::string j) { return (i.size()>j.size()); }


void usage()
{
 std::cout << "BoggleSolver permet de trouver les mots qu'il est possible de former a partir d'une grille de Boggle" << std::endl;
 std::cout << "Arguments : " << std::endl;
 std::cout << "\t --d <filepath>. Dictionnaire utilise" << std::endl;
 std::cout << "\t --g <str>. Grille de lettres. Les lignes sont separees par des ','. Ex : ABC,DEF,IJK" << std::endl;
 exit(1);

}

int main(int argc, char **argv) {
    
    std::string dictionnary;
    std::string grid;

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
	else if(strcmp(argv[i],"--g")==0)
	{
	    if(i+1<argc)
	    {
	      grid = argv[i+1];
	      i++;
	    }
	    else
	      usage();
	}
	else
	  usage();
	i++;
      
    }
    if(dictionnary.size()==0 || grid.size()==0)
      usage();
    Dictionnary d =  Dictionnary(dictionnary);
    
   
   
   
   
   
   
   
   BoggleSolver b = BoggleSolver();
   b.setGrid(grid);
    b.setDictionnary(d);
  std::vector<std::string> res = b.giveMeWords();
  
   std::cout << "-------------------------------------------------------------------------------" << std::endl; 
   std::cout << "Avec le dictionnaire sélectionné, et la grille suivante " << std::endl;
   b.displayGrid();
   std::cout << "Il est possible de former les mots suivants :" << std::endl;
   

   for(std::vector<std::string>::iterator it = res.begin(); it != res.end();++it)
   {
    std::cout << *it << std::endl; 
   }
   std::cout << "-------------------------------------------------------------------------------" << std::endl; 
    return 0;
}


