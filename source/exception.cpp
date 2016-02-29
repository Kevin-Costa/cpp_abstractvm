//
// exception.cpp for exception in /home/costa_b/rendu/abstractvm
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Feb 18 13:48:36 2015 Kevin Costa
// Last update Sun Mar  1 16:35:45 2015 Kevin Costa
//

#include	<string>
#include	"exception.hpp"

exception::exception(std::string const &error) throw() :
  m_error(error)
{
}

exception::~exception(void) throw()
{
}

char const	*exception::what(void) const throw()
{
  return(m_error.c_str());
}
