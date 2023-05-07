/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:13:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

// Default constructor
Animal::Animal()
{
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	*this = other;
}

// Destructor
Animal::~Animal()
{
}

// Copy assignment operator
Animal &Animal::operator=(const Animal &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


