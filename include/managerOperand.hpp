//
// managerOperand.hpp for managerOperand in /home/plasko_a/projet/cplusplus/cpp_abstractvm/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Feb 28 03:37:41 2015 Antoine Plaskowski
// Last update Sat Feb 28 08:33:18 2015 Antoine Plaskowski
//

#ifndef		MANAGEROPERAND_HPP_
# define	MANAGEROPERAND_HPP_

# include	<string>
# include	"ioperand.hpp"

class		managerOperand
{
public:
  struct	managerOperandPrecision
  {
    enum ioperand::precision	precision;
    ioperand	*(*ptr)(std::string const &);
  };
  static ioperand	*createOperand(enum ioperand::precision const precision, const std::string &value);
private:
  static ioperand	*createInt8(std::string const &value);
  static ioperand	*createInt16(std::string const &value);
  static ioperand	*createInt32(std::string const &value);
  static ioperand	*createFloat(std::string const &value);
  static ioperand	*createDouble(std::string const &value);
};

#endif		/* !MANAGEROPERAND_HPP_ */
