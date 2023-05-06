/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:07:45 by znichola          #+#    #+#             */
/*   Updated: 2023/04/25 17:36:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include <iostream>

// Default constructor
// FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap \"" << _name << "\"" << " has been spawned"
		<< std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap \"" << _name << "\" Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy \"" << _name << "\"  assignment operator called" << std::endl;
	//*this = other;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap \"" << _name << "\" destructor called " << std::endl;
}

// Copy assignment operator
// FragTrap &FragTrap::operator=(const FragTrap &other)

void	FragTrap::highFivesGuys(void)
{
	std::cout << "\"" << _name << "\""
		<< " is asking for a high five from the guys, let's gooo!"
		<< std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (_energyPoints - _attackDamage > 0)
	{
		std::cout << "\"" << _name << "\" Frag attacks " << target

		<< " for " << _attackDamage << " damage, yikes!"
		<< std::endl;
		_energyPoints -= _attackDamage;
	}
	else
	{
		std::cout << "\"" << _name << "\"" << " can't Frag attack for "
		<< _attackDamage << ", need another "
		<< _attackDamage - _energyPoints << " energy points" << std::endl;
	}
}
