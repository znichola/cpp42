/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:17 by znichola          #+#    #+#             */
/*   Updated: 2023/05/31 08:00:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"
#include "utils.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") {}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
	*this = other;
}

// Destructor
Cure::~Cure() {}

// Copy assignment operator
Cure &Cure::operator=(const Cure &other)
{
	AMateria::operator=(other);
	return *this;
}

AMateria	*Cure::clone() const
{
	_garbageBin[_i] = new Cure();
	_notFreed[_i] = 1;
	_i += 1;
	return _garbageBin[_i - 1];
	// return new Cure();
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target << "'s wounds *" << std::endl;
	AMateria::use(target);
}
