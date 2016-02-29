//
// managerOperand.cpp for managerOperand in /home/plasko_a/projet/cplusplus/cpp_abstractvm/source
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Feb 28 08:22:33 2015 Antoine Plaskowski
// Last update Sun Mar  1 14:53:03 2015 Antoine Plaskowski
//

#include	<stdint.h>
#include	<limits>
#include	<exception>
#include	<sstream>
#include	"operand.hpp"
#include	"managerOperand.hpp"

ioperand	*managerOperand::createOperand(enum ioperand::precision const precision, const std::string &value)
{
  static struct	managerOperandPrecision m_o_p[] =
    {
      {ioperand::Int8, managerOperand::createInt8},
      {ioperand::Int16, managerOperand::createInt16},
      {ioperand::Int32, managerOperand::createInt32},
      {ioperand::Float, managerOperand::createFloat},
      {ioperand::Double, managerOperand::createDouble}
    };
  size_t const	s_m_o_p = sizeof(m_o_p) / sizeof(*m_o_p);
  size_t	i;

  for (i = 0; i < s_m_o_p; i++)
    if (m_o_p[i].precision == precision)
      return (m_o_p[i].ptr(value));
  throw std::exception();
}

ioperand	*managerOperand::createInt8(std::string const &value)
{
  std::stringstream	ss(value);
  intmax_t	int_value;

  ss >> int_value;
  if (ss.fail() == true ||
      int_value < std::numeric_limits<int8_t>::min() ||
      int_value > std::numeric_limits<int8_t>::max())
    throw exception("overflow int8");
  return (new operand<int8_t>(static_cast<int8_t>(int_value), ioperand::Int8));
}

ioperand	*managerOperand::createInt16(std::string const &value)
{
  std::stringstream	ss(value);
  int16_t	int_value;

  ss >> int_value;
  if (ss.fail() == true)
    throw exception("overflow int16");
  return (new operand<int16_t>(int_value, ioperand::Int16));
}

ioperand	*managerOperand::createInt32(std::string const &value)
{
  std::stringstream	ss(value);
  int32_t	int_value;

  ss >> int_value;
  if (ss.fail() == true)
    throw exception("overflow int32");
  return (new operand<int32_t>(int_value, ioperand::Int32));
}

ioperand	*managerOperand::createFloat(std::string const &value)
{
  std::stringstream	ss(value);
  float		int_value;

  ss >> int_value;
  if (ss.fail() == true)
    throw exception("overflow float");
  return (new operand<float>(int_value, ioperand::Float));
}

ioperand	*managerOperand::createDouble(std::string const &value)
{
  std::stringstream	ss(value);
  double	int_value;

  ss >> int_value;
  if (ss.fail() == true)
    throw exception("overflow double");
  return (new operand<double>(int_value, ioperand::Double));
}
