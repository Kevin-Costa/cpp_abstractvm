//
// ioperand.hpp for ioperand in /home/costa_b/rendu/abstractvm
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Mon Feb 16 16:10:11 2015 Kevin Costa
// Last update Sun Mar  1 14:31:39 2015 Antoine Plaskowski
//

#ifndef		IOPERAND_HPP_
# define	IOPERAND_HPP_

# include	<string>

class		ioperand
{
public:
  enum		precision
    {
      Int8 = 0,
      Int16 = 1,
      Int32 = 2,
      Float = 3,
      Double = 4
    };
  virtual ~ioperand(void);
  virtual std::string const	&toString(void) const = 0;
  virtual ioperand::precision	getPrecision(void) const = 0;
  virtual ioperand	*operator+(const ioperand &rhs) const = 0;
  virtual ioperand	*operator-(const ioperand &rhs) const = 0;
  virtual ioperand	*operator*(const ioperand &rhs) const = 0;
  virtual ioperand	*operator/(const ioperand &rhs) const = 0;
  virtual ioperand	*operator%(const ioperand &rhs) const = 0;
};

#endif		/* !IOPERAND_HPP_ */
