/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:00:59 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 13:10:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	this->_Name = newName;
	this->_Armed = false;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void) const
{
	if (this->_Armed)
		std::cout	<< this->_Name
					<< " attacks with their "
					<< this->_Weapon.getType() << std::endl;
	else
		std::cout	<< this->_Name
					<< " can't attack, they are unarmed!" << std::endl;
}

void HumanB::setWeapon(Weapon newWeapon)
{
	this->_Armed = true;
	this->_Weapon = newWeapon;
}
