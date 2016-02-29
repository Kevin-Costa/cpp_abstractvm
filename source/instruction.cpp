//
// instruction.cpp for instruction in /home/plasko_a/projet/cplusplus/cpp_abstractvm/source
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Feb 28 04:50:27 2015 Antoine Plaskowski
// Last update Sun Mar  1 16:27:02 2015 Kevin Costa
//

#include	<iostream>
#include	<sstream>
#include	<stdint.h>
#include	"exception.hpp"
#include	"instruction.hpp"

instruction::instruction(ioperand *arg, instruction::type const type) :
  m_arg(arg)
{
  static struct instructionExecute const i_e[] =
    {
      {instruction::Push, instruction::push},
      {instruction::Pop, instruction::pop},
      {instruction::Dump, instruction::dump},
      {instruction::Assert, instruction::assert},
      {instruction::Add, instruction::add},
      {instruction::Sub, instruction::sub},
      {instruction::Mul, instruction::mul},
      {instruction::Div, instruction::div},
      {instruction::Mod, instruction::mod},
      {instruction::Print, instruction::print},
      {instruction::Exit,  instruction::exit}
    };
  static size_t	const	s_i_e = sizeof(i_e) / sizeof(*i_e);
  size_t	i;

  for (i = 0; i < s_i_e; i++)
    if (i_e[i].type == type)
      {
	m_execute = i_e[i].execute;
	return;
      }
  throw std::exception();
}

instruction::~instruction(void)
{
}

bool		instruction::execute(std::list<ioperand *> &stack) const
{
  if (m_execute == NULL)
    throw exception("m_execute == NULL");
  return (m_execute(stack, m_arg));
}

bool		instruction::push(std::list<ioperand *> &stack, ioperand *arg)
{
  if (arg == NULL)
    throw exception("no value to push");
  stack.push_back(arg);
  return (true);
}

bool		instruction::pop(std::list<ioperand *> &stack, ioperand *)
{
  if (stack.empty() == true)
    throw exception("pop on stack empty");
  ioperand	*back_op = stack.back();
  stack.pop_back();
  delete back_op;
  return (true);  
}

bool		instruction::dump(std::list<ioperand *> &stack, ioperand *)
{
  for (std::list<ioperand *>::iterator it = stack.begin(); it != stack.end(); ++it)
    {
      if (*it == NULL)
	throw exception("wtf *it == NULL");
      std::cout << (*it)->toString() << std::endl;
    }
  return (true);
}

bool		instruction::assert(std::list<ioperand *> &stack, ioperand *arg)
{
  if (stack.empty() == true)
    throw exception("stack is empty");
  ioperand	*front_op = stack.back();

  if (front_op == NULL || arg == NULL)
    throw exception("wtf front_op == NULL || arg == NULL");
  if (front_op->toString() == arg->toString())
    throw exception("assert fail");
  return (true);
}

bool		instruction::add(std::list<ioperand *> &stack, ioperand *)
{
  if (stack.size() < 2)
    throw exception("the stack has no two operand");
  ioperand	*v1 = stack.back();
  stack.pop_back();
  ioperand	*v2 = stack.back();
  stack.pop_back();
  if (v1 == NULL || v2 == NULL)
    throw exception("v1 == NULL || v2 == NULL");
  stack.push_back(*v2 + *v1);
  return (true);
}

bool		instruction::sub(std::list<ioperand *> &stack, ioperand *)
{
  if (stack.size() < 2)
    throw exception("the stack has no two operand");
  ioperand	*v1 = stack.back();
  stack.pop_back();
  ioperand	*v2 = stack.back();
  stack.pop_back();
  if (v1 == NULL || v2 == NULL)
    throw exception("v1 == NULL || v2 == NULL");
  stack.push_back(*v2 - *v1);
  return (true);
}

bool		instruction::mul(std::list<ioperand *> &stack, ioperand *)
{
  if (stack.size() < 2)
    throw exception("the stack has no two operand");
  ioperand	*v1 = stack.back();
  stack.pop_back();
  ioperand	*v2 = stack.back();
  stack.pop_back();
  if (v1 == NULL || v2 == NULL)
    throw exception("v1 == NULL || v2 == NULL");
  stack.push_back(*v2 * *v1);
  return (true);
}

bool		instruction::div(std::list<ioperand *> &stack, ioperand *)
{
  if (stack.size() < 2)
    throw exception("the stack has no two operand");
  ioperand	*v1 = stack.back();
  stack.pop_back();
  ioperand	*v2 = stack.back();
  stack.pop_back();
  if (v1 == NULL || v2 == NULL)
    throw exception("v1 == NULL || v2 == NULL");
  stack.push_back(*v2 / *v1);
  return (true);
}

bool		instruction::mod(std::list<ioperand *> &stack, ioperand *)
{
  if (stack.size() < 2)
    throw exception("the stack has no two operand");
  ioperand	*v1 = stack.back();
  stack.pop_back();
  ioperand	*v2 = stack.back();
  stack.pop_back();
  if (v1 == NULL || v2 == NULL)
    throw exception("v1 == NULL || v2 == NULL");
  stack.push_back(*v2 % *v1);
  return (true);
}

bool		instruction::print(std::list<ioperand *> &stack, ioperand *)
{
  std::stringstream	ss;
  int8_t	c;

  if (stack.empty() == true)
    throw exception("stack is empty");
  ioperand	*front_op = stack.back();
  if (front_op == NULL)
    throw exception("wtf front_op == NULL");
  if (front_op->getPrecision() != ioperand::Int8)
    throw exception("print : presicion de operand != Int8");
  ss << front_op->toString();
  ss >> c;
  std::cout << static_cast<char>(c);
  return (true);
}

bool		instruction::exit(std::list<ioperand *> &, ioperand *)
{
  return (false);
}
