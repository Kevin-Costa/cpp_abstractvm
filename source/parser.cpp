//
// parser.cpp for parser in /home/plasko_a/projet/cplusplus/cpp_abstractvm
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Feb 26 13:22:59 2015 Antoine Plaskowski
// Last update Sun Mar  1 13:50:04 2015 Antoine Plaskowski
//

#include	<exception>
#include	<fstream>
#include	"parser.hpp"
#include	"managerOperand.hpp"
#include	"instruction.hpp"

static struct parser::instructionType const	i_t[] =
  {
    {instruction::Push, "push", true},
    {instruction::Pop, "pop", false},
    {instruction::Dump, "dump", false},
    {instruction::Assert, "assert", true},
    {instruction::Add, "add", false},
    {instruction::Sub, "sub", false},
    {instruction::Mul, "mul", false},
    {instruction::Div, "div", false},
    {instruction::Mod, "mod", false},
    {instruction::Print, "print", false},
    {instruction::Exit, "exit", false}
  };

static size_t const	s_i_t = sizeof(i_t) / sizeof(*i_t);

static struct parser::operandPrecision const	o_p[] =
  {
    {ioperand::Int8, "int8"},
    {ioperand::Int16, "int16"},
    {ioperand::Int32, "int32"},
    {ioperand::Float, "float"},
    {ioperand::Double, "double"}
  };

static size_t const	s_o_p = sizeof(o_p) / sizeof(*o_p);

static size_t		isInstruction(std::string const &str)
{
  size_t		i;

  for (i = 0; i < s_i_t; i++)
    if (i_t[i].str == str)
      return (i);
  throw std::exception();
}

static size_t		isOperand(std::string const &str)
{
  size_t		i;

  for (i = 0; i < s_o_p; i++)
    if (o_p[i].str == str)
      return (i);
  throw std::exception();
}

static struct lexer::token	*getToken(lexer &lexer, lexer::type const type)
{
  struct lexer::token	*token = lexer.next_token();
  if (token == NULL || token->type != type)
    {
      delete token;
      throw std::exception();
    }
  return (token);
}

static ioperand		*getArg(lexer &lexer)
{
  struct lexer::token	*token = getToken(lexer, lexer::Identifier);
  size_t		ope = isOperand(token->str);
  delete token;
  token = getToken(lexer, lexer::Opening_parenthesis);
  delete token;
  token = getToken(lexer, lexer::Integer);
  ioperand		*arg = managerOperand::createOperand(o_p[ope].precision, token->str);
  delete token;
  token = getToken(lexer, lexer::Closing_parenthesis);
  delete token;
  return (arg);
}

static instruction	*automate(lexer &lexer, struct lexer::token *identifier)
{
  size_t		ins = isInstruction(identifier->str);
  ioperand		*arg = i_t[ins].arg == true ? getArg(lexer) : NULL;
  struct lexer::token	*token = lexer.next_token();

  if (token != NULL && token->type != lexer::Separator)
    {
      delete token;
      throw std::exception();
    }
  delete token;
  return (new instruction(arg, i_t[ins].type));
}

parser::parser(std::istream &file) :
  m_queue()
{
  lexer		lexer(file);
  struct lexer::token	*token;

  for (token = lexer.next_token(); token != NULL; token = lexer.next_token())
    {
      if (token->type != lexer::Separator)
	{
	  if (token->type != lexer::Identifier)
	    throw std::exception();
	  else
	    m_queue.push(automate(lexer, token));
	}
      delete token;
    }
}

parser::~parser(void)
{
  while (m_queue.empty() == false)
    {
      delete m_queue.front();
      m_queue.pop();
    }
}

instruction	*parser::next_instruction(void)
{
  instruction	*ret;

  if (m_queue.empty() == false)
    {
      ret = m_queue.front();
      m_queue.pop();
    }
  else
    ret = NULL;
  return (ret);
}
