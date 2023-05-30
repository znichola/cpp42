/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/30 21:02:58 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"
#include "utils.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria(other) {}

// Destructor
Ice::~Ice() {}

// Copy assignment operator
Ice &Ice::operator=(const Ice &other)
{
	AMateria::operator=(other);
	return *this;
}

AMateria	*Ice::clone() const
{
	return new Ice();
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
	AMateria::use(target);
}
