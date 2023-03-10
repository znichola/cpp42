/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:43:11 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 13:23:50 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string newName, Weapon &newWeapon) : _Weapon(newWeapon)
{
	this->_Name = newName;
}

HumanA::~HumanA()
{
}

void HumanA::attack(void) const
{
	std::cout	<< this->_Name
				<< " attacks with their "
				<< this->_Weapon.getType() << std::endl;
}
