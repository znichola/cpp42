/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:13 by znichola          #+#    #+#             */
/*   Updated: 2023/03/31 03:39:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed()
{
	this->_num = 0;
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int &integer)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(integer << _offset);
}

Fixed::Fixed(const float &floater)
{
	std::cout << "Float constructor called" << std::endl;
	_num = roundf(floater * (1U << _offset));
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_num = other.getRawBits();
	return *this;
}

float	Fixed::toFloat(void) const						{ return _num / (1U << _offset); }
int		Fixed::toInt(void) const						{ return _num >> _offset; }

bool	Fixed::operator  >  (const Fixed *rhs)			{ return _num >  rhs->_num; }
bool	Fixed::operator  <  (const Fixed *rhs)			{ return _num <  rhs->_num; }
bool	Fixed::operator  >= (const Fixed *rhs)			{ return _num >= rhs->_num; }
bool	Fixed::operator  <= (const Fixed *rhs)			{ return _num <= rhs->_num; }
bool	Fixed::operator  == (const Fixed *rhs)			{ return _num == rhs->_num; }
bool	Fixed::operator  != (const Fixed *rhs)			{ return _num != rhs->_num; }

Fixed	Fixed::operator  +  (const Fixed &rhs) const	{ Fixed ret(_num + rhs._num); return ret; }
Fixed	Fixed::operator  -  (const Fixed &rhs) const	{ Fixed ret(_num - rhs._num); return ret; }
Fixed	Fixed::operator  *  (const Fixed &rhs) const	{ Fixed ret(_num * rhs._num); return ret; }
Fixed	Fixed::operator  /  (const Fixed &rhs) const	{ Fixed ret(_num / rhs._num); return ret; }

Fixed	&Fixed::operator ++ (void)						{ _num += (1U << _offset); return *this; }
Fixed	&Fixed::operator -- (void)						{ _num -= (1U << _offset); return *this; }
Fixed	Fixed::operator  ++ (int)						{ Fixed old = *this; operator++(); return old; }
Fixed	Fixed::operator  -- (int)						{ Fixed old = *this; operator--(); return old; }

Fixed	&Fixed::min(Fixed &a, Fixed &b) const			{ return a > b ? b : a;}
Fixed	&Fixed::max(Fixed &a, Fixed &b) const			{ return a > b ? a : b;}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) const	{ return a > b ? b : a;}
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) const	{ return a > b ? a : b;}

void	Fixed::setRawBits(int const raw)	{ _num = raw; }
int		Fixed::getRawBits(void) const		{ return _num; }

std::ostream	&operator<<(std::ostream &os, const Fixed &other) { os << other.toFloat(); return os; }
