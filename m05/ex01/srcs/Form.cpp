/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:48:18 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 16:11:50 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sstream>
#include <iostream>

#include "Form.hpp"

static std::string getID()
{
	std::ostringstream os;
	os << clock();
	return os.str();
}

int Form::validateGrade(const int grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
	return grade;
}

Form::Form()
	: _name("F_" + getID()), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const int s, const int e)
	: _name("F_" + getID()), _signed(false),
	_signGrade(validateGrade(s)),
	_execGrade(validateGrade(e)) {}

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed),
	_signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
	(void)other;
	std::cout << "can't copy assign form, the paperwork is too complicated!"
	<< std::endl;
	return *this;
}

std::string	Form::getName() const { return _name; }
bool		Form::getSignedStat() const { return _signed; }
int			Form::getSignGrade() const { return _signGrade; }
int			Form::getExecGrade() const { return _execGrade; }

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "<"
		<< f.getName() << " "
		<< (f.getSignedStat() ? "signed  " : "unsigned") << " "
		<< "sign grade: " << f.getSignGrade() << " "
		<< "exec grade: " << f.getExecGrade()
	<< ">";
	return os;
}
