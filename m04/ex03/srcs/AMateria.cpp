/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/31 08:12:45 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "AMateria.hpp"

#include <iostream>

unsigned int	AMateria::_i = 0;
AMateria		*AMateria::_garbageBin[MAX_AMATERIA] = {0};
int				AMateria::_notFreed[MAX_AMATERIA] = {0};

// Default constructor
AMateria::AMateria() : _type("FooBar") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

// Copy constructor
AMateria::AMateria(const AMateria &other) : _type(other._type) {}

// Destructor
AMateria::~AMateria() {}

// Copy assignment operator
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "* can't transmute (copy assign) materia * " << std::endl;
	(void)other;
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
	/* do some shit to use ur ability on the target */
}

void AMateria::emptyGarbage(void)
{
	for (unsigned i = 0; i < _i; i++) { delete _garbageBin[i]; };
	_i = 0;
}

void AMateria::removeMat(AMateria *mat)
{
	for (unsigned int i = 0; i < _i; i++)
	{
		if (mat == _garbageBin[i])
		{
			delete _garbageBin[i];
			_notFreed[i] = 0;
			return ;
		}
	}
	delete mat;
}
