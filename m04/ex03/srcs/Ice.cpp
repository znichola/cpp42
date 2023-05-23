/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 23:57:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

// Default constructor
Ice::Ice()
{
}

// Copy constructor
Ice::Ice(const Ice &other)
{
	*this = other;
}

// Destructor
Ice::~Ice()
{
}

// Copy assignment operator
Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


