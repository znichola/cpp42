/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:07:45 by znichola          #+#    #+#             */
/*   Updated: 2023/05/14 23:05:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

const int FragTrap::_defaultHP = 100;
const int FragTrap::_defaultEP = 100;
const int FragTrap::_defaultAD = 30;

FragTrap::FragTrap() : ClapTrap("Defaultus_Fragus")
{
	_hitPoints    = _defaultHP;
	_energyPoints = _defaultEP;
	_attackDamage = _defaultAD;
	std::cout << "FragTrap \"" << _name << "\" has been spawned" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints    = _defaultHP;
	_energyPoints = _defaultEP;
	_attackDamage = _defaultAD;
	std::cout << "FragTrap \"" << _name << "\"" << " has been spawned"
		<< std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap \"" << _name
		<< "\" Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy \""
		<< _name << "\"  assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap \"" << _name << "\" destructor called " << std::endl;
}

void	FragTrap::highFivesGuys(void) const
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
