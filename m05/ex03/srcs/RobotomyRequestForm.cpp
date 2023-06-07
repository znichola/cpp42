/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:30:08 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 21:51:56 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RR", 72, 45, false), _target("Generic") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RR", 72, 45, false), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm("RR",
	other.getExecGrade(),
	other.getSignGrade(),
	other.getSignedStat()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrate &executor) const
{
	AForm::execute(executor);
	if (std::rand() % 2)
		std::cout << _target
		<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		std::cout << _target
		<< " pardone's pardon has been rejected by Zaphod Beeblebrox." << std::endl;
}
