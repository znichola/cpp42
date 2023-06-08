/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:08:57 by znichola          #+#    #+#             */
/*   Updated: 2023/06/08 11:11:26 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) {(void)other;}
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(const std::string form, const std::string target) const
{
	const std::string forms[] = {
		"shrubbery creation", "robotomy request", "presidential pardon"
		};
	int match = -1;
	for (int i = 0; i < 3; i++)
		if (forms[i] == form)
		{
			match = i;
			break ;
		}
	switch (match)
	{
	case 0: return new ShrubberyCreationForm(target);
	case 1: return new RobotomyRequestForm(target);
	case 2: return new PresidentialPardonForm(target);
	default: throw Intern::NonExistantForm();
	}
}

const char *Intern::NonExistantForm::what() const throw()
{
	return "Form does not exist";

}
