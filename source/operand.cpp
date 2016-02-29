//
// operand.cpp for operand in /home/plasko_a/projet/cplusplus/cpp_abstractvm/source
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Feb 28 08:01:30 2015 Antoine Plaskowski
// Last update Sun Mar  1 15:02:36 2015 Antoine Plaskowski
//

#include	"operand.hpp"
#include	"exception.hpp"

template<>
ioperand	*operand<double>::operator%(ioperand const &) const
{
  throw exception("Modulo by decimale");
}

template<>
ioperand	*operand<float>::operator%(ioperand const &) const
{
  throw exception("Modulo by decimale");
}

template<>
ioperand	*operand<float>::operator/(ioperand const &rhs) const
{
  ioperand	*ret;
  ioperand	*tmp;

  if (getPrecision() < rhs.getPrecision())
    {
      tmp = managerOperand::createOperand(rhs.getPrecision(), toString());
      ret = *tmp / rhs;
      delete tmp;
    }
  else
    {
      float	v_lhs;
      float	v_rhs;
      std::stringstream	ss;

      ss << toString();
      ss >> v_lhs;
      ss.clear();
      ss << rhs.toString();
      ss >> v_rhs;
      ret = new operand<float>(v_lhs / v_rhs, getPrecision());
    }
  return (ret);
}

template<>
ioperand	*operand<double>::operator/(ioperand const &rhs) const
{
  ioperand	*ret;
  ioperand	*tmp;

  if (getPrecision() < rhs.getPrecision())
    {
      tmp = managerOperand::createOperand(rhs.getPrecision(), toString());
      ret = *tmp / rhs;
      delete tmp;
    }
  else
    {
      double	v_lhs;
      double	v_rhs;
      std::stringstream	ss;

      ss << toString();
      ss >> v_lhs;
      ss.clear();
      ss << rhs.toString();
      ss >> v_rhs;
      ret = new operand<double>(v_lhs / v_rhs, getPrecision());
    }
  return (ret);
}
