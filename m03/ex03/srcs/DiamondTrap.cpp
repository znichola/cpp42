/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:25:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/14 23:05:30 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap()
{
	_name = "Defaultus_Diannus";
	ClapTrap::_name = _name + "_clapname";
	_hitPoints    = FragTrap::_defaultHP;
	_energyPoints = ScavTrap::_defaultEP;
	_attackDamage = FragTrap::_defaultAD;
	std::cout << "DiamondTrap \"" << _name << "\"" << " has been spawned"
	<< std::endl;
}


// Default constructor
DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clapname"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_hitPoints    = FragTrap::_defaultHP;
	_energyPoints = ScavTrap::_defaultEP;
	_attackDamage = FragTrap::_defaultAD;

	std::cout << "DiamondTrap \"" << _name << "\"" << " has been spawned"
	<< std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) :
ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap \"" << _name
		<< "\" Copy constructor called" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {}

// Copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap Copy \""
		<< _name << "\"  assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	FragTrap::attack(target);
}

void	DiamondTrap::WhoAmI(void)
{
	std::cout	<< "This is a DiamondTrap called \""
				<< _name << "\""
				<< " also known by it's Calp name \""
				<< ClapTrap::_name << "\"" << std::endl;
}
