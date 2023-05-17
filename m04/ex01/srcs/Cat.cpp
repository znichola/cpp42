/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 21:45:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

// Default constructor
Cat::Cat() : Animal()
{
	std::cout << "   Cat: Constructing a " << type << std::endl;
	type = "Cat";
	noggin = new Brain();
}

// Copy constructor
Cat::Cat(const Cat &other)
{
	std::cout << "   Cat: Copy Constructing a " << type << std::endl;
	noggin = other.noggin;
	Animal::operator=(other);
}

// Destructor
Cat::~Cat()
{
	delete noggin;
	std::cout << "   Cat: Destroying a " << type << std::endl;
}

// Copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "   Cat: Copy Assigning a " << type << std::endl;
	Animal::operator=(other);
	noggin = other.noggin;
	return *this;
}

// method
void	Cat::makeSound(void) const
{
	std::cout << "Miawww Miaowww" << std::endl;
}

const Brain	*Cat::exposeBrain(void) const
{
	return (noggin);
}
