/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/25 10:52:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice &other)
{
	*this = other;
}

// Destructor
Ice::~Ice() {}

// Copy assignment operator
Ice &Ice::operator=(const Ice &other)
{
	// TODO: insert return statement here(void)other;

	/*
		what does copying the type not makes sense means ?! for the yellow bulb
	*/
	return *this;
}

AMateria	*Ice::clone() const
{
	return new Ice();
}

void		use(ICharacter &target)
{
	std::cout << "* shoots and ice bolt at " << target << " *" << std::endl;
}
