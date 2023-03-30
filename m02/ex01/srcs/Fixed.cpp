/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:13 by znichola          #+#    #+#             */
/*   Updated: 2023/03/31 01:37:44 by znichola         ###   ########.fr       */
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
	this->_num = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called called" << std::endl;
	return this->_num;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called called" << std::endl;
	this->_num = raw;
}
std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return os;
}

float Fixed::toFloat(void) const
{
	// return this->getRawBits() >> _fracBits + this->getRawBits() ;
	return _num / (1U << _offset);
}

int Fixed::toInt(void) const
{
	return _num >> _offset;
}
