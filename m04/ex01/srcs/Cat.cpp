/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/22 11:02:17 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

// Default constructor
Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "   Cat: Constructing a " << type << std::endl;
	_brain = new Brain();
	std::cout << "my brain " << &_brain << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other)
{
	std::cout << "   Cat: Copy Constructing a " << type << std::endl;
	_brain = new Brain(*other.exposeBrain());
	// _brain = other._brain;
	Animal::operator=(other);
}

// Destructor
Cat::~Cat()
{
	std::cout << "   Cat: Destroying a " << type << std::endl;
	delete _brain;
}

// Copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "   Cat: Copy Assigning a " << type << std::endl;
	_brain = other._brain;
	Animal::operator=(other);
	return *this;
}

// method
void	Cat::makeSound(void) const
{
	std::cout << "Miawww Miaowww" << std::endl;
}

const Brain	*Cat::exposeBrain(void) const
{
	return (_brain);
}

void Cat::think(void) const
{
	std::cout << "   Cat: thought : " << _brain->getIdea(1) << std::endl;
}
