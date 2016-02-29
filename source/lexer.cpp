//
// token.cpp for token in /home/plasko_a/projet/cplusplus/cpp_abstractvm
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Feb 26 13:36:25 2015 Antoine Plaskowski
// Last update Sat Feb 28 12:05:52 2015 Antoine Plaskowski
//

#include	<string>
#include	<vector>
#include	<fstream>
#include	<algorithm>
#include	"exception.hpp"
#include	"lexer.hpp"

static struct lexer::regex_lexer const	regex[] =
  {
    {"abcdefghifklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", lexer::Identifier, "abcdefghifklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"},
    {"\n", lexer::Separator, "\n"},
    {"(", lexer::Opening_parenthesis, "("},
    {")", lexer::Closing_parenthesis, ")"},
    {"-0123456789", lexer::Integer, ".0123456789"},
  };

static size_t const	size_regex = sizeof(regex) / sizeof(*regex);

#include	<iostream>

static size_t		get_type(int const c)
{
  size_t		i;

  for (i = 0; i < size_regex; i++)
    if (std::find(regex[i].regex.begin(), regex[i].regex.end(), c) != regex[i].regex.end())
      return (i);
  throw exception("this char is not is invalid!\n");
}

static int	peek_char(std::istream &file)
{
  static std::string const	separator("\n");
  static std::string const	blank(" \t");

  while (std::find(blank.begin(), blank.end(), file.peek()) != blank.end())
    file.get();
  if (file.peek() == ';')
    do
      file.get();
    while (std::find(separator.begin(), separator.end(), file.peek()) == separator.end()
	   && file.peek() != std::char_traits<char>::eof());
  return (file.peek());
}

lexer::lexer(std::istream &file) :
  m_queue()
{
  while (peek_char(file) != std::char_traits<char>::eof())
    {
      size_t		type = get_type(file.peek());
      struct token	*token = new struct token;

      token->type = regex[type].type;
      do
	token->str += static_cast<char>(file.get());
      while (std::find(regex[type].str.begin(), regex[type].str.end(), file.peek()) != regex[type].str.end());
      m_queue.push(token);
    }
}

lexer::~lexer(void)
{
  while (m_queue.empty() == false)
    {
      delete m_queue.front();
      m_queue.pop();
    }
}

struct lexer::token	*lexer::next_token(void)
{
  struct lexer::token	*ret;

  if (m_queue.empty() == false)
    {
      ret = m_queue.front();
      m_queue.pop();
    }
  else
    ret = NULL;
  return (ret);
}
