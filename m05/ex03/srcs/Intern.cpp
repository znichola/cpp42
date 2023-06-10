/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:08:57 by znichola          #+#    #+#             */
/*   Updated: 2023/06/10 12:42:15 by znichola         ###   ########.fr       */
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

static AForm *_ShrubberyCreationForm(const std::string t)
{
	return new ShrubberyCreationForm(t);
}

static AForm *_RobotomyRequestForm(const std::string t)
{
	return new RobotomyRequestForm(t);
}

static AForm *_PresidentialPardonForm(const std::string t)
{
	return new PresidentialPardonForm(t);
}

AForm *Intern::makeForm(const std::string form, const std::string target) const
{
	const std::string forms[] = {
		"shrubbery creation", "robotomy request", "presidential pardon"
		};
	static AForm *(*func[])(const std::string) = {
		_ShrubberyCreationForm, _RobotomyRequestForm, _PresidentialPardonForm
		};
	for (int i = 0; i < 3; i++)
		if (forms[i] == form)
			return func[i](target);
	throw Intern::NonExistantForm(form);
}

Intern::NonExistantForm::NonExistantForm(const std::string msg)
	: _msg("\"" + msg + "\" Form does not exist") {}

Intern::NonExistantForm::~NonExistantForm() throw()
{}

const char *Intern::NonExistantForm::what() const throw()
{
	return _msg.c_str();
}
