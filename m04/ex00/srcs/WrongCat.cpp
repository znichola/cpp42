/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:44:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:44:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat()
{
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
}

// Destructor
WrongCat::~WrongCat()
{
}

// Copy assignment operator
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


