//
// operand.hpp for operand in /home/costa_b/rendu/abstractvm
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Mon Feb 16 16:14:32 2015 Kevin Costa
// Last update Sun Mar  1 15:02:20 2015 Antoine Plaskowski
//

#ifndef		OPERAND_HPP_
# define	OPERAND_HPP_

# include	<string>
# include	<iostream>
# include	<sstream>
# include	"ioperand.hpp"
# include	"exception.hpp"
# include	"managerOperand.hpp"

template <typename T>
class		operand : public ioperand
{
public:
  operand(T const value, ioperand::precision const precision);
  ~operand(void);
  std::string const	&toString(void) const;
  ioperand::precision	getPrecision(void) const;
  ioperand		*operator+(ioperand const &rhs) const;
  ioperand		*operator-(ioperand const &rhs) const;
  ioperand		*operator*(ioperand const &rhs) const;
  ioperand		*operator/(ioperand const &rhs) const;
  ioperand		*operator%(ioperand const &rhs) const;
private:
  ioperand::precision	m_precision;
  T			m_value;
  std::string		m_str;
};

template <typename T>
operand<T>::operand(T const value, ioperand::precision const precision) :
  m_precision(precision),
  m_value(value),
  m_str()
{
  std::stringstream	ss;

  ss << value;
  ss >> m_str;
}

template <typename T>
operand<T>::~operand(void)
{
}

template <typename T>
std::string const	&operand<T>::toString(void) const
{
  return (m_str);
}

template <typename T>
ioperand::precision	operand<T>::getPrecision(void) const
{
  return (m_precision);
}

template <typename T>
ioperand		*operand<T>::operator+(ioperand const &rhs) const
{
  ioperand		*ret;
  ioperand		*tmp;

  if (getPrecision() < rhs.getPrecision())
    {
      tmp = managerOperand::createOperand(rhs.getPrecision(), toString());
      ret = *tmp + rhs;
      delete tmp;
    }
  else
    {
      T			v_lhs;
      T			v_rhs;
      std::stringstream	ss;

      ss << toString();
      ss >> v_lhs;
      ss.clear();
      ss << rhs.toString();
      ss >> v_rhs;
      ret = new operand<T>(v_lhs + v_rhs, getPrecision());
    }
  return (ret);
}

template <typename T>
ioperand		*operand<T>::operator-(ioperand const &rhs) const
{
  ioperand		*ret;
  ioperand		*tmp;

  if (getPrecision() < rhs.getPrecision())
    {
      tmp = managerOperand::createOperand(rhs.getPrecision(), toString());
      ret = *tmp - rhs;
      delete tmp;
    }
  else
    {
      T			v_lhs;
      T			v_rhs;
      std::stringstream	ss;

      ss << toString();
      ss >> v_lhs;
      ss.clear();
      ss << rhs.toString();
      ss >> v_rhs;
      ret = new operand<T>(v_lhs - v_rhs, getPrecision());
    }
  return (ret);
}

template <typename T>
ioperand		*operand<T>::operator*(ioperand const &rhs) const
{
  ioperand		*ret;
  ioperand		*tmp;

  if (getPrecision() < rhs.getPrecision())
    {
      tmp = managerOperand::createOperand(rhs.getPrecision(), toString());
      ret = *tmp * rhs;
      delete tmp;
    }
  else
    {
      T			v_lhs;
      T			v_rhs;
      std::stringstream	ss;

      ss << toString();
      ss >> v_lhs;
      ss.clear();
      ss << rhs.toString();
      ss >> v_rhs;
      ret = new operand<T>(v_lhs * v_rhs, getPrecision());
    }
  return (ret);
}

template <typename T>
ioperand		*operand<T>::operator/(ioperand const &rhs) const
{
  ioperand		*ret;
  ioperand		*tmp;

  if (getPrecision() < rhs.getPrecision())
    {
      tmp = managerOperand::createOperand(rhs.getPrecision(), toString());
      ret = *tmp / rhs;
      delete tmp;
    }
  else
    {
      T			v_lhs;
      T			v_rhs;
      std::stringstream	ss;

      ss << toString();
      ss >> v_lhs;
      ss.clear();
      ss << rhs.toString();
      ss >> v_rhs;
      if (v_rhs == 0)
	throw exception("Divide by 0");
      ret = new operand<T>(v_lhs / v_rhs, getPrecision());
    }
  return (ret);
}

template <typename T>
ioperand		*operand<T>::operator%(ioperand const &rhs) const
{
  ioperand		*ret;
  ioperand		*tmp;

  if (getPrecision() < rhs.getPrecision())
    {
      tmp = managerOperand::createOperand(rhs.getPrecision(), toString());
      ret = *tmp % rhs;
      delete tmp;
    }
  else
    {
      T			v_lhs;
      T			v_rhs;
      std::stringstream	ss;

      ss << toString();
      ss >> v_lhs;
      ss.clear();
      ss << rhs.toString();
      ss >> v_rhs;
      if (v_rhs == 0)
	throw exception("Divide by 0");
      ret =  new operand<T>(v_lhs % v_rhs, getPrecision());
    }
  return (ret);
}

template <>
ioperand		*operand<float>::operator/(ioperand const &rhs) const;
template <>
ioperand		*operand<double>::operator/(ioperand const &rhs) const;
template<>
ioperand		*operand<float>::operator%(ioperand const &rhs) const;
template<>
ioperand		*operand<double>::operator%(ioperand const &rhs) const;

#endif		/* !OPERAND_HPP_ */
