/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:26:02 by znichola          #+#    #+#             */
/*   Updated: 2023/06/10 10:20:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sstream>
#include <iostream>

#include "Bureaucrate.hpp"

static std::string getID()
{
	std::ostringstream os;
	os << clock();
	return os.str();
}

int Bureaucrate::validateGrade(const int grade)
{
	if (grade > 150)
		throw Bureaucrate::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrate::GradeTooHighException();
	return grade;
}

// Default constructor
Bureaucrate::Bureaucrate()
	: _name("Cog_" + getID()), _grade(150) {}

Bureaucrate::Bureaucrate(int grade)
	: _name("Cog_" + getID()), _grade(validateGrade(grade)) {}

// Copy constructor
Bureaucrate::Bureaucrate(const Bureaucrate &other)
	: _name(other._name), _grade(other._grade) {}

// Destructor
Bureaucrate::~Bureaucrate() { }

// Copy assignment operator
Bureaucrate &Bureaucrate::operator=(const Bureaucrate &other)
{
	(void)other;
	std::cout << "can't copy assign beurocrats, they will not tolerate it!"
	<< std::endl;
	return *this;
}

std::string	Bureaucrate:: getName() const { return _name; }
int			Bureaucrate::getGrade() const { return _grade; }

void Bureaucrate::prompte() { _grade = validateGrade(_grade - 1); }
void Bureaucrate:: demote() { _grade = validateGrade(_grade + 1); }

const char *Bureaucrate::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char *Bureaucrate::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}
