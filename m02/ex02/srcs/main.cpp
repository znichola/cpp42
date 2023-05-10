/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/10 19:53:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

template <typename A, typename B>
static void	testFixed(A a, B b, char s);

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	std::cout << "---- Given main ----" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "---- My main ----" << std::endl;

	std::cout << "Ints" << std::endl;
	testFixed<int, int>(42, 7, '+');
	testFixed<int, int>(42, 990, '-');
	testFixed<int, int>(21, 2, '*');
	testFixed<int, int>(61, 3, '/');
	testFixed<int, int>(7919, 7, '/');

	std::cout << std::endl << "Floating points" << std::endl;
	testFixed<float, float>(42.1f, 98.1, '+');
	testFixed<float, float>(72.1f, 12.1, '-');
	testFixed<float, float>(1.01f, 2.15, '*');
	testFixed<float, float>(42.01f, 2.15, '/');
	testFixed<float, float>(500.01f, 1.0015, '/');

	Fixed x(42);

	std::cout << std::endl << "Incramentors" << std::endl;
	std::cout << "x is "    << x << std::endl;
	std::cout << "++x : x = " << ++x << std::endl;
	std::cout << "x++ : x = " << x++ << std::endl;
	std::cout << "x-- : x = " << x-- << std::endl;
	std::cout << "--x : x = " << --x << std::endl;
	std::cout << "x is "    << x << std::endl;

	x = 73.042f;
	std::cout << std::endl << "Min Max" << std::endl;
	std::cout << "(" << x << ", " << a << ")" << std::endl;
	std::cout << "max " << Fixed::max(x, a) << std::endl;
	std::cout << "min " << Fixed::min(x, a) << std::endl;
	std::cout << std::endl;
	return 0;
}

template <typename A, typename B>
static void	testFixed(A a, B b, char s)
{
	switch (s)
	{
	case '+':
		std::cout << "stdlib: " << a << " + " << b << " = " << (A)a + (B)b << std::endl;
		std::cout << " melib: " << Fixed(a) << " + " << Fixed(b) << " = " << Fixed(a) + Fixed(b) << std::endl;
		std::cout << std::endl;
		break;
	case '-':
		std::cout << "stdlib: " << a << " - " << b << " = " << (A)a - (B)b << std::endl;
		std::cout << " melib: " << Fixed(a) << " - " << Fixed(b) << " = " << Fixed(a) - Fixed(b) << std::endl;
		std::cout << std::endl;
		break;
	case '*':
		std::cout << "stdlib: " << a << " * " << b << " = " << a * b << std::endl;
		std::cout << " melib: " << Fixed(a) << " * " << Fixed(b) << " = " << Fixed(a) * Fixed(b) << std::endl;
		std::cout << std::endl;
		break;
	case '/':
		std::cout << "stdlib: " << a << " / " << b << " = " << (float)a / (float)b << std::endl;
		std::cout << " melib: " << Fixed(a) << " / " << Fixed(b) << " = " << Fixed(a) / Fixed(b) << std::endl;
		std::cout << std::endl;
		break;
	default:
		break;
	}
}
