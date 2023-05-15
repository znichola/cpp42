/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:44:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:51:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

#include <iostream>

// Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "   WrongCat: Constructing a " << type << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "   WrongCat: Copy Constructing a " << type << std::endl;
	WrongAnimal::operator=(other);
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "   WrongCat: Destroying a " << type << std::endl;
}

// Copy assignment operator
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	return *this;
}

// method
void	WrongCat::makeSound(void) const
{
	std::cout << "Miawwwrongg Miaowwwrongg" << std::endl;
}
