/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:45:40 by znichola          #+#    #+#             */
/*   Updated: 2023/04/01 12:24:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"
#include "Fixed.hpp"

Point::~Point() { }
Point::Point()						{ _x = 0; _y = 0; }
Point::Point(Fixed x, Fixed y)		{ _x = x; _y = y; }
Point::Point(const Point &other)	{ *this = other; }

Point	&Point::operator=(const Point &other)	{ _x = other._x; _y = other._y; return *this; }

Fixed Point::getX(void) const { return _x; }
Fixed Point::getY(void) const { return _y; }

Point	Point::sub  (const Point &a, const Point &b) { return Point(a._x - b._x, a._y - b._y); }
Fixed	Point::cross(const Point &a, const Point &b) { return a._x * b._y - a._y * b._x; }

bool	Point::leftOf(const Point &a, const Point &b, const Point &p)
{
	Point ab = sub(a, b);
	Point pa = sub(p, a);

	// std::cout << std::endl << p << " left of line "<< a << b << " is " << (cross(pa, ab) < 0) << std::endl;

	return cross(pa, ab) < 0;
}

std::ostream	&operator<<(std::ostream &os, const Point &other)
{
	os << "(" << other.getX().toFloat() << ", " << other.getY().toFloat() << ")";
	return os;
}
