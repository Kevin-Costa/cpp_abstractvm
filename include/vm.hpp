//
// vm.hpp for vm in /home/plasko_a/projet/cplusplus/cpp_abstractvm
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Mar  1 13:51:00 2015 Antoine Plaskowski
// Last update Sun Mar  1 14:45:50 2015 Antoine Plaskowski
//

#ifndef		VM_HPP_
# define	VM_HPP_

# include	<fstream>
# include	<list>
# include	"parser.hpp"
# include	"ioperand.hpp"

class		vm
{
public:
  vm(std::istream &file);
  ~vm(void);
  bool		execute(void);
private:
  parser	m_parser;
  std::list<ioperand *>	m_stack;
};

#endif		/* !VM_HPP_ */
