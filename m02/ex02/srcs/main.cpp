/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:12 by znichola          #+#    #+#             */
/*   Updated: 2023/03/31 16:34:51 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "Ints" << std::endl;
	std::cout << Fixed(123) << std::endl;
	std::cout << Fixed(-123) << std::endl;
	std::cout << Fixed(-0) << std::endl;
	std::cout << Fixed(1) + Fixed(1) << std::endl;

	std::cout << std::endl << "Floating points" << std::endl;
	std::cout << Fixed(-42.42f) << std::endl;
	std::cout << Fixed(42.42f) << std::endl;
	std::cout << Fixed(21.21f) << std::endl;
	std::cout << Fixed(42.42f) + Fixed(21.21f) << std::endl;

	return 0;
}
