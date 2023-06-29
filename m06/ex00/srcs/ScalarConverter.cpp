/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:35:33 by znichola          #+#    #+#             */
/*   Updated: 2023/06/29 20:04:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cctype>

#define INT		1
#define CHAR	2
#define FLOAT	3
#define DOUBLE	4


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
												{ (void)other; return *this; }

#define MEGA_UGLY(v) \
{\
char cc = static_cast<char>(v); \
std::cout << "char : " \
<< (impossible ? "impossible" : "") \
<< ((!std::isprint(cc) && !impossible)? "Non displayable" : ""); \
if (!impossible && std::isprint(cc)) std::cout << "'"<< cc << "'"; \
std::cout << std::endl; \
\
std::cout << "int : " << (impossible ? "impossible" : ""); \
if (!impossible) std::cout << static_cast<int>(v); std::cout << std::endl; \
\
float ff = static_cast<float>(v); \
std::cout << "float : " << (ff == 0.0f ? "0.0" : ""); \
if (ff != 0.0f) std::cout << ff; \
if (ff == static_cast<int>(v)) std::cout << ".0";\
std::cout << "f" << std::endl; \
\
float dd = static_cast<float>(v); \
std::cout << "double : " << (dd == 0.0f ? "0.0" : ""); \
if (dd != 0.0f) std::cout << dd; \
if (dd == static_cast<int>(v)) std::cout << ".0";\
std::cout << std::endl; \
}

void ScalarConverter::convert(const std::string &s)
{
	std::stringstream ss(s);
	int type = 0;
	bool impossible = false;

	int		i;
	char	c;
	float	f;
	double	d;

	if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
	{
		type = CHAR;
		c = s[1];
	}
	else if (s.size() >= 4 && s.back() == 'f' && s.find('.') != std::string::npos)
	{
		ss.str(s.substr(0, s.size() - 1));
		type = FLOAT;
		ss >> f;
	}
	else if (s.find('.') != std::string::npos)
	{
		type = DOUBLE;
		ss >> d;
	}
	else if (s == "-inff")
	{
		type = FLOAT;
		impossible = true;
		f = -1 * std::numeric_limits<float>::infinity();
	}
	else if (s == "inff")
	{
		type = FLOAT;
		impossible = true;
		f = std::numeric_limits<float>::infinity();
	}
	else if (s == "nanf")
	{
		type = FLOAT;
		impossible = true;
		f = std::numeric_limits<float>::signaling_NaN();
	}
	else if (s == "-inf")
	{
		type = DOUBLE;
		impossible = true;
		d = -1 * std::numeric_limits<double>::infinity();
	}
	else if (s == "inf")
	{
		type = DOUBLE;
		impossible = true;
		d = std::numeric_limits<double>::infinity();
	}
	else if (s == "nan")
	{
		type = DOUBLE;
		impossible = true;
		d = std::numeric_limits<double>::signaling_NaN();
	}
	else
	{
		type = INT;
		ss >> i;
	}
	if (ss.fail())
	{
		std::cout << "you failed to give me valid input" << std::endl;
		return ;
	}
	switch (type)
	{
	case INT:    MEGA_UGLY(i) break;
	case CHAR:   MEGA_UGLY(c) break;
	case FLOAT:  MEGA_UGLY(f) break;
	case DOUBLE: MEGA_UGLY(d) break;
	}
}
