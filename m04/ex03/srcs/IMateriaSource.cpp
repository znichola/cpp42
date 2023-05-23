/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:02:37 by znichola          #+#    #+#             */
/*   Updated: 2023/05/24 01:02:37 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "IMateriaSource.hpp"

// Default constructor
IMateriaSource::IMateriaSource()
{
}

// Copy constructor
IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
	*this = other;
}

// Destructor
IMateriaSource::~IMateriaSource()
{
}

// Copy assignment operator
IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


