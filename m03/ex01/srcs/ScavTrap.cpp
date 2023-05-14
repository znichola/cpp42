/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:07:45 by znichola          #+#    #+#             */
/*   Updated: 2023/05/14 19:04:59 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Defaultus_Scavus")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap \"" << _name << "\" has been spawned" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap \"" << _name << "\"" << " has been spawned"
		<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap \"" << _name
		<< "\" Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy \"" << _name
		<< "\"  assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap \"" << _name << "\" destructor called " << std::endl;
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "\"" << _name << "\""
		<< " is in Gate Keeper mode, beware!"
		<< std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints - _attackDamage > 0)
	{
		std::cout << "\"" << _name << "\" Scav attacks " << target
		<< " for " << _attackDamage << " damage, yikes!"
		<< std::endl;
		_energyPoints -= _attackDamage;
	}
	else
	{
		std::cout << "\"" << _name << "\"" << " can't Scav attack for "
		<< _attackDamage << ", need another "
		<< _attackDamage - _energyPoints << " energy points" << std::endl;
	}
}
