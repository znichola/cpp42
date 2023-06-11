/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:26:02 by znichola          #+#    #+#             */
/*   Updated: 2023/06/10 11:12:11 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sstream>
#include <iostream>

#include "Bureaucrate.hpp"
#include "Form.hpp"

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

void Bureaucrate::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << *this << " couldn't sign " << f
			<< " because " << e.what() << "." << std::endl;
	}

}

const char *Bureaucrate::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrate::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrate &b)
{
	os << "<" << b.getName() << ", bureaucrat grade " << b.getGrade() << ">";
	return os;
}
