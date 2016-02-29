//
// token.hpp for token in /home/plasko_a/projet/cplusplus/cpp_abstractvm
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Feb 26 13:36:31 2015 Antoine Plaskowski
// Last update Sat Feb 28 11:46:59 2015 Antoine Plaskowski
//

#ifndef		TOKEN_HPP_
# define	TOKEN_HPP_

# include	<fstream>
# include	<queue>

class		lexer
{
public:
  enum		type
    {
      Identifier,
      Separator,
      Opening_parenthesis,
      Closing_parenthesis,
      Integer,
      End
    };
  struct	token
  {
    std::string	str;
    enum lexer::type	type;
  };
  struct		regex_lexer
  {
    std::string		regex;
    enum lexer::type	type;
    std::string		str;
  };
  lexer(std::istream &file);
  ~lexer(void);
  struct lexer::token	*next_token(void);
private:
  std::queue<struct lexer::token *>	m_queue;
};

#endif		/* !LEXER_HPP_ */
