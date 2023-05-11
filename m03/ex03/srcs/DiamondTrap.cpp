/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:25:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/11 10:54:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

// Default constructor
DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clapname"), FragTrap(name), ScavTrap(name)
{
	FragTrap t("tmp");

	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = FragTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap \"" << _name << "\"" << " has been spawned"
	<< std::endl;
}

// Copy constructor
// DiamondTrap::DiamondTrap(const DiamondTrap &other)
// {
// 	*this = other;
// }

// Destructor
DiamondTrap::~DiamondTrap()
{
}

// Copy assignment operator
// DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
// {
// 	(void)other;
// 	// TODO: insert return statement here
// 	return *this;
// }

void DiamondTrap::WhoAmI(void)
{
	std::cout	<< "This is a DiamondTrap called \""
				<< _name << "\""
				<< " also known by it's Calp name \""
				<< ClapTrap::_name << "\"" << std::endl;
}
