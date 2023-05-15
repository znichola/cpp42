/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:56:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:56:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

// Default constructor
Brain::Brain()
{
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	*this = other;
}

// Destructor
Brain::~Brain()
{
}

// Copy assignment operator
Brain &Brain::operator=(const Brain &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


