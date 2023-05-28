/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/28 22:18:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria(other)
{
	*this = other;
}

// Destructor
Ice::~Ice() {}

// Copy assignment operator
Ice &Ice::operator=(const Ice &other)
{
	_type = other._type;
	return *this;
}

AMateria	*Ice::clone() const
{
	return new Ice();
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots and ice bolt at " << target << " *" << std::endl;
}
