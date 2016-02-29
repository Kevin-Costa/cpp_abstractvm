//
// parser.hpp for parser in /home/plasko_a/projet/cplusplus/cpp_abstractvm
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Feb 26 13:23:08 2015 Antoine Plaskowski
// Last update Sat Feb 28 11:40:35 2015 Antoine Plaskowski
//

#ifndef		PARSER_HPP_
# define	PARSER_HPP_

# include	<string>
# include	<queue>
# include	<fstream>
# include	"ioperand.hpp"
# include	"lexer.hpp"
# include	"instruction.hpp"

class		parser
{
public:
  struct	instructionType
  {
    enum instruction::type	type;
    std::string	str;
    bool	arg;
  };
  struct	operandPrecision
  {
    enum ioperand::precision	precision;
    std::string	str;
  };
  parser(std::istream &file);
  ~parser(void);
  instruction	*next_instruction(void);
private:
  std::queue<instruction *>	m_queue;
};

#endif		/* !PARSER_HPP_ */
