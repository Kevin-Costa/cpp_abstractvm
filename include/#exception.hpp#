//
// exception.hpp for exception in /home/costa_b/rendu/abstractvm
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Feb 18 13:44:36 2015 Kevin Costa
// Last update Sun Mar  1 16:35:49 2015 Kevin Costa
//

#ifndef		EXCEPTION_HPP_
# define	EXCEPTION_HPP_

# include	<string>
# include	<exception>

class exception : public std::exception
{
public:
  exception(std::string const &error) throw();
  virtual ~exception(void) throw();
  virtual char const	*what(void) const throw();
private:
  std::string	m_error;
};

#endif		/* !EXCEPTION_HPP_ */
