//
// instruction.hpp for instruction in /home/plasko_a/projet/cplusplus/cpp_abstractvm/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Feb 28 04:52:29 2015 Antoine Plaskowski
// Last update Sun Mar  1 11:09:00 2015 Antoine Plaskowski
//

#ifndef		INSTRUCTION_HPP_
# define	INSTRUCTION_HPP_

# include	<list>
# include	"ioperand.hpp"

class		instruction
{
public:
  enum		type
    {
      Push,
      Pop,
      Dump,
      Assert,
      Add,
      Sub,
      Mul,
      Div,
      Mod,
      Print,
      Exit
    };
  struct	instructionExecute
  {
    enum instruction::type	type;
    bool	(*execute)(std::list<ioperand *> &stack, ioperand *arg);
  };
  instruction(ioperand *arg, instruction::type const type);
  ~instruction(void);
  bool	execute(std::list<ioperand *> &stack) const;
private:
  static bool	push(std::list<ioperand *> &stack, ioperand *arg);
  static bool	pop(std::list<ioperand *> &stack, ioperand *arg);
  static bool	dump(std::list<ioperand *> &stack, ioperand *arg);
  static bool	assert(std::list<ioperand *> &stack, ioperand *arg);
  static bool	add(std::list<ioperand *> &stack, ioperand *arg);
  static bool	sub(std::list<ioperand *> &stack, ioperand *arg);
  static bool	mul(std::list<ioperand *> &stack, ioperand *arg);
  static bool	div(std::list<ioperand *> &stack, ioperand *arg);
  static bool	mod(std::list<ioperand *> &stack, ioperand *arg);
  static bool	print(std::list<ioperand *> &stack, ioperand *arg);
  static bool	exit(std::list<ioperand *> &stack, ioperand *arg);
  ioperand	*m_arg;
  bool		(*m_execute)(std::list<ioperand *> &stack, ioperand *arg);
};

#endif		/* !INSTRUCTION_HPP_ */
