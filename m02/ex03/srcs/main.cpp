/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:19:12 by znichola          #+#    #+#             */
/*   Updated: 2023/04/01 12:55:47 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

# define C(a,b) a##b
# define CAT(a,b) C(a,b)

# define Q(x) #x
# define QUOTE(x) Q(x)

#define BLUE(w) QUOTE(\033[94m w\033[0m)
#define GREEN(w) QUOTE(\033[92m w\033[0m)

bool	bsp( Point const a, Point const b, Point const c, Point const point);

static void	test(const Point &a, const Point &b, const Point &c, const Point &p);
static void	draw(int u, int v, const Point &a, const Point &b, const Point &c);

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	std::cout << "Testing triangles and points" << std::endl;

	test(Point(0,0), Point(0, 4), Point(5, 0), Point(-3, 3));
	test(Point(0,0), Point(0, 4), Point(5, 0), Point(1, 1));
	test(Point(0,0), Point(0, 4), Point(5, 0), Point(0, 1));
	test(Point(0,0), Point(0, 4), Point(5, 0), Point(0, 0));
	test(Point(0,0), Point(0, 4), Point(5, 0), Point(1, 2));
	test(Point(0,0), Point(0, 4), Point(5, 0), Point(4, 0.5f));

	std::cout << std::endl << "draw triangle" << std::endl;

	draw(5, 5, Point(0, 0), Point(0.4f, 5), Point(5, 2));
	return 0;
}

static void	test(const Point &a, const Point &b, const Point &c, const Point &p)
{
	std::cout	<< "point " << p
				<< "	is" << (bsp(a, b, c, p) ? BLUE(inside) : GREEN(outside))
				<< "traingle " << a << " " << b << " " << c << std::endl;
}

static void	draw(int u, int v, const Point &a, const Point &b, const Point &c)
{
	for (float x = 0; x < u; x += 0.3)
	{
		for (float y = 0; y < v; y += 0.3)
			std::cout << (bsp(a, b, c, Point(x, y)) ? BLUE(#) : GREEN(#));
		std::cout << std::endl;
	}
}
