/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:07:45 by znichola          #+#    #+#             */
/*   Updated: 2023/04/19 16:54:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include <iostream>

// Default constructor
// ScavTrap::ScavTrap() {}

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
	*this = other;
	std::cout << "ScavTrap \"" << _name << "\" Copy constructor called" << std::endl; 
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy \"" << _name << "\"  assignment operator called" << std::endl; 
	//*this = other;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap \"" << _name << "\" destructor called " << std::endl; 
}

// Copy assignment operator
// ScavTrap &ScavTrap::operator=(const ScavTrap &other)

void	ScavTrap::guardGate(void)
{
	std::cout << "\"" << _name << "\""
		<< " is in Gate Keeper mode, beware!"
		<< std::endl;
}

// TODO: need to fix it so this function actually gets called!
void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints - _attackDamage > 0)
	{
		std::cout << "\"" << _name << "\" scav attacks " << target
		<< " for " << _attackDamage << " damage, yikes!"
		<< std::endl;
		_energyPoints -= _attackDamage;
	}
	else
	{
		std::cout << "\"" << _name << "\"" << " can't scav attack for " 
		<< _attackDamage << ", need another "
		<< _attackDamage - _energyPoints << " energy points" << std::endl;
	}
}

