/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:12 by znichola          #+#    #+#             */
/*   Updated: 2023/03/31 03:41:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_num;
	static const int	_offset = 8;

public:
// Default constructor
	Fixed();

// Copy constructor
	Fixed(const Fixed &other);
	Fixed(const int &integer);
	Fixed(const float &floater);

	// Destructor
	~Fixed();

// Copy assignment operator
	Fixed	&operator = (const Fixed &other);

// Comparison operators
	bool	operator >  (const Fixed *rhs);
	bool	operator <  (const Fixed *rhs);
	bool	operator >= (const Fixed *rhs);
	bool	operator <= (const Fixed *rhs);
	bool	operator == (const Fixed *rhs);
	bool	operator != (const Fixed *rhs);

// Arithmetic operators
	Fixed	operator + (const Fixed &rhs) const ;
	Fixed	operator - (const Fixed &rhs) const ;
	Fixed	operator * (const Fixed &rhs) const ;
	Fixed	operator / (const Fixed &rhs) const ;

// Incramentors
	Fixed	&operator ++ (void);
	Fixed	&operator -- (void);
	Fixed	operator  ++ (int);
	Fixed	operator  -- (int);

// Funcs
	Fixed	&min(const Fixed &a, const Fixed &b) const;
	Fixed	&max(const Fixed &a, const Fixed &b) const;
	Fixed	&min(Fixed &a, Fixed &b) const;
	Fixed	&max(Fixed &a, Fixed &b) const;

// Acessors
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

// Converters
	float	toFloat( void ) const;
	int		toInt( void ) const;

	friend std::ostream & operator<< (std::ostream &os, const Fixed &other);
};

#endif /* FIXED_HPP */
