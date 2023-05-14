/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:29:34 by znichola          #+#    #+#             */
/*   Updated: 2023/05/14 23:05:42 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>


ClapTrap::ClapTrap() :
_name("Defaultus"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap \"" << _name << "\" has been spawned" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap \"" << _name << "\" has been spawned" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap &other) :
_name(other._name), _hitPoints(other._hitPoints),
_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap \"" << _name
		<< "\" Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap \"" << _name
		<< "\" destructor called " << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	_name         = other._name;
	_hitPoints    = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap Copy \"" << _name
			<< "\"  assignment operator called" << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energyPoints - _attackDamage > 0)
	{
		std::cout << "\"" << _name << "\" attacks " << target
		<< " for " << _attackDamage << " damage, yikes!"
		<< std::endl;
		_energyPoints -= _attackDamage;
	}
	else
	{
		std::cout << "\"" << _name << "\"" << " can't attack for "
		<< _attackDamage << ", need another "
		<< _attackDamage - _energyPoints << " energy points" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout	<< "\"" << _name << "\" takes " << amount
			<< " damage, ouch!"
			<< std::endl;
	if (_hitPoints <= 0)
	{
		_hitPoints = 0;
 		std::cout << "\"" << _name
			<< "\"" << " has 0 health left :(" << std::endl;

	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints - int(amount) < 0)
	{
		std::cout << "\"" << _name << "\"" << " can't repair for "
		<< amount << ", need another "
		<< amount - _energyPoints << " energy points" << std::endl;
		return ;
	}
	_energyPoints -= amount;
	_hitPoints += amount;
	std::cout	<< "\"" << _name << "\" is repaired by " << amount
			<< std::endl;
}

void	ClapTrap::statRep(void) const
{
	std::cout	<< "~~ status-report: \"" << _name << "\""
			<< " dmg:" << _attackDamage
			<< " HP:" << _hitPoints
			<< " EP:" << _energyPoints
			<< "" << std::endl;
}

void	ClapTrap::setAttackDmg(unsigned int amount)
{
	_attackDamage = amount;
	std::cout	<< "\"" << _name << "\"" << " new attack damage is "
			<< _attackDamage << std::endl;
}
