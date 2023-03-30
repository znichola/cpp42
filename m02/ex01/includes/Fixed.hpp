/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:12 by znichola          #+#    #+#             */
/*   Updated: 2023/03/31 01:37:46 by znichola         ###   ########.fr       */
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
	Fixed & operator=(const Fixed &other);


	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	friend std::ostream & operator<< (std::ostream &os, const Fixed &other);
};

#endif /* FIXED_HPP */
