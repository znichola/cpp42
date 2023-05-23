/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 15:52:43 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

// Default constructor
Cat::Cat() : AAnimal()
{
	type = "Cat";
	std::cout << "   Cat: Constructing a " << type << std::endl;
	_brain = new Brain();
}

// Copy constructor
Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "   Cat: Copy Constructing a " << type << std::endl;
	_brain = new Brain();
	*_brain = *other._brain;
}

// Destructor
Cat::~Cat()
{
	delete _brain;
	std::cout << "   Cat: Destroying a " << type << std::endl;
}

// Copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
	AAnimal::operator=(other);
	std::cout << "   Cat: Copy Assigning a " << type << std::endl;
	*_brain = *other._brain;
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
