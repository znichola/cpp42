/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:08:57 by znichola          #+#    #+#             */
/*   Updated: 2023/06/07 21:16:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <string>

#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Default constructor
Intern::Intern()
{
}

// Copy constructor
Intern::Intern(const Intern &other)
{
	*this = other;
}

// Destructor
Intern::~Intern()
{
}

// Copy assignment operator
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}

AForm &Intern::makeForm(const std::string form, const std::string target) const
{
	// static AForm *forms[] = {new PresidentialPardonForm( target), new ShrubberyCreationForm};
	static AForm *()
}
