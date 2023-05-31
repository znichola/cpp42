/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/31 08:22:09 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "AMateria.hpp"

#include <iostream>

unsigned int	AMateria::_i = 0;
AMateria		*AMateria::_garbageBin[MAX_AMATERIA] = {0};

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
