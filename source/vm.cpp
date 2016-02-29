//
// vm.cpp for vm in /home/plasko_a/projet/cplusplus/cpp_abstractvm
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Mar  1 13:59:31 2015 Antoine Plaskowski
// Last update Sun Mar  1 14:46:18 2015 Antoine Plaskowski
//

#include	<fstream>
#include	"exception.hpp"
#include	"parser.hpp"
#include	"vm.hpp"
#include	"instruction.hpp"

vm::vm(std::istream &file) :
  m_parser(file),
  m_stack()
{
}

vm::~vm(void)
{
  while (m_stack.empty() == false)
    {
      ioperand	*back_op = m_stack.back();
      m_stack.pop_back();
      delete back_op;
    }
}

bool	vm::execute(void)
{
  for (instruction *ins = m_parser.next_instruction(); ins != NULL; ins = m_parser.next_instruction())
    {
      if (ins->execute(m_stack) == false)
	{
	  delete ins;
	  return (true);
	}
      delete ins;
    }
  throw exception("not terminate by exit");
}
