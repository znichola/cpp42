/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:12 by znichola          #+#    #+#             */
/*   Updated: 2023/03/31 17:13:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int32_t					_num;
	static const int	_offset = 8;

public:
	~Fixed();

	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int &integer);
	Fixed(const float &floater);
// Copy assignment operator
	Fixed	&operator = (const Fixed &other);


// Comparison operators
	bool	operator >  (const Fixed &rhs) const;
	bool	operator <  (const Fixed &rhs) const;
	bool	operator >= (const Fixed &rhs) const;
	bool	operator <= (const Fixed &rhs) const;
	bool	operator == (const Fixed &rhs) const;
	bool	operator != (const Fixed &rhs) const;

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
static const Fixed	&min(const Fixed &a, const Fixed &b);
static const Fixed	&max(const Fixed &a, const Fixed &b);
static Fixed		&min(Fixed &a, Fixed &b);
static Fixed		&max(Fixed &a, Fixed &b);

// Acessors
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

// Converters
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

// Helper functions; really, they could be called friends.
std::ostream	&operator<< (std::ostream &os, const Fixed &other);
Fixed			rawFixed(int raw);

#endif /* FIXED_HPP */
