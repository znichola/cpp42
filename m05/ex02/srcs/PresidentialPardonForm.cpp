/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:30:16 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 21:53:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PP", 25, 5, false), _target("Generic") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PP", 25, 5, false), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm("PP",
	other.getExecGrade(),
	other.getSignGrade(),
	other.getSignedStat()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrate &executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
