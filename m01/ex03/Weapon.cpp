/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:34:13 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 13:21:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string t)
{
	this->setType(t);
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(void) const
{
	return this->type;
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}
