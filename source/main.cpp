//
// main.cpp for main in /home/plasko_a/projet/cplusplus/cpp_abstractvm
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Feb 26 12:50:22 2015 Antoine Plaskowski
// Last update Sun Mar  1 17:50:17 2015 Antoine Plaskowski
//

#include	<iostream>
#include	<exception>
#include	"vm.hpp"

int		main(int argc, char **argv)
{
  if (argc == 1)
    {
      try
	{
	  vm	vm(std::cin);
	  
	  vm.execute();
	}
      catch (std::exception const &e)
	{
	  std::cerr << e.what() << std::endl;
	}
    }
  for (int i = 1; i < argc; i++)
    {
      try
	{
	  std::ifstream	file(argv[i]);
	  vm		vm(file);

	  vm.execute();
	}
      catch (std::exception const &e)
	{
	  std::cerr << e.what() << std::endl;
	}
    }
  return (0);
}
