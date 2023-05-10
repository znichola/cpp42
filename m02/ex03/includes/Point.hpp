/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:45:40 by znichola          #+#    #+#             */
/*   Updated: 2023/04/01 11:06:37 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed	_x;
	Fixed	_y;

public:
// Destructor
	~Point();

// Default constructor
	Point();
	Point(Fixed x, Fixed y);

// Copy constructor
	Point(const Point &other);

// Copy assignment operator
	Point &operator = (const Point &other);

	Fixed	getX(void) const;
	Fixed	getY(void) const;

	static Point	sub   (const Point &a, const Point &b);
	static Fixed	cross (const Point &a, const Point &b);
	static bool		leftOf(const Point &a, const Point &b, const Point &p);
};

std::ostream	&operator<< (std::ostream &os, const Point &other);

#endif /* POINT_HPP */
