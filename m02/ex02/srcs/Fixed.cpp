/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/10 19:38:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>

// Default constructor

Fixed::~Fixed() { }

Fixed::Fixed() 						{ this->_num = 0U; }
Fixed::Fixed(const Fixed &other)	{ *this = other; }
Fixed::Fixed(const int &i)			{ _num = i << _offset; }
Fixed::Fixed(const float &f)		{ _num = int(f * float(1U << _offset) + (f >= 0 ? 0.5 : -0.5)); }

Fixed	&Fixed::operator=(const Fixed &other) 			{ _num = other._num; return *this; }

// Comparison operators
bool	Fixed::operator  >  (const Fixed &rhs) const	{ return _num >  rhs._num; }
bool	Fixed::operator  <  (const Fixed &rhs) const	{ return _num <  rhs._num; }
bool	Fixed::operator  >= (const Fixed &rhs) const	{ return _num >= rhs._num; }
bool	Fixed::operator  <= (const Fixed &rhs) const	{ return _num <= rhs._num; }
bool	Fixed::operator  == (const Fixed &rhs) const	{ return _num == rhs._num; }
bool	Fixed::operator  != (const Fixed &rhs) const	{ return _num != rhs._num; }

// Arithmetic operators
Fixed	Fixed::operator  +  (const Fixed &rhs) const	{ return rawFixed(_num + rhs._num); }
Fixed	Fixed::operator  -  (const Fixed &rhs) const	{ return rawFixed(_num - rhs._num); }
Fixed	Fixed::operator  *  (const Fixed &rhs) const	{ return rawFixed(int64_t(_num) * int64_t(rhs._num) >> _offset); }
Fixed	Fixed::operator  /  (const Fixed &rhs) const	{ return rawFixed((int64_t(_num) << _offset) / int64_t(rhs._num)); }

// Incramentors
Fixed	&Fixed::operator ++ (void)						{ _num += 1U; return *this; }
Fixed	&Fixed::operator -- (void)						{ _num -= 1U; return *this; }
Fixed	Fixed::operator  ++ (int)						{ Fixed old = *this; operator++(); return old; }
Fixed	Fixed::operator  -- (int)						{ Fixed old = *this; operator--(); return old; }

// Funcs
Fixed		&Fixed::min (Fixed &a, Fixed &b)			{ return a > b ? b : a; }
Fixed		&Fixed::max (Fixed &a, Fixed &b)			{ return a > b ? a : b; }
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) { return a > b ? b : a; }
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) { return a > b ? a : b; }

// Acessors
void	Fixed::setRawBits(int const raw)				{ _num = raw; }
int		Fixed::getRawBits(void) const					{ return _num; }

// Converters
float	Fixed::toFloat(void) const						{ return _num / float(1U << _offset); }
int		Fixed::toInt(void) const						{ return _num >> _offset; }

// Helper functions; really, they could be called friends.
std::ostream	&operator<<(std::ostream &os, const Fixed &other) { os << other.toFloat(); return os; }
Fixed			rawFixed(int raw) { Fixed res; res.setRawBits(raw); return res; }
