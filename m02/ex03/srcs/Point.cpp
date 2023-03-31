/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:45:40 by znichola          #+#    #+#             */
/*   Updated: 2023/03/31 23:57:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

Point::~Point() { }
Point::Point()								{ _x = 0; _y = 0; }
Point::Point(Fixed x, Fixed y) 				{ _x = x; _y = y; }
Point::Point(const Point &other) 			{ *this = other; }

Point &Point::operator=(const Point &other)	{ _x = other._x; _y = other._y; }
