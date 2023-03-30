/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:12 by znichola          #+#    #+#             */
/*   Updated: 2023/03/30 23:33:39 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_fixedPoint;
	static const int	_fracBits = 8;

public:
// Default constructor
	Fixed();

// Copy constructor
	Fixed(const Fixed &other);

// Destructor
	~Fixed();

// Copy assignment operator
	Fixed & operator=(const Fixed &other);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif /* FIXED_HPP */
