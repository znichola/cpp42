/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:38:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/11 15:32:39 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Data::Data(int xx, int yy) : x(xx), y(yy) {}

std::ostream &operator<<(std::ostream &os, const Data &d)
{
	os << "(" << d.x << ", " << d.y << ")";
	return os;
}
