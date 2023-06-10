/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:48:18 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 17:11:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int AForm::validateGrade(const int grade)
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	if (grade < 1)
		throw AForm::GradeTooHighException();
	return grade;
}

std::string AForm::getID()
{
	std::ostringstream os;
	os << clock();
	return os.str();
}

AForm::AForm()
	: _name("Form_" + getID()), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const int s, const int e)
	: _name("Form_" + getID()), _signed(false),
	_signGrade(validateGrade(s)),
	_execGrade(validateGrade(e)) {}

AForm::AForm(const std::string t, const int s, const int e, bool stat)
	: _name(t + "form_" + getID()), _signed(stat),
	_signGrade(validateGrade(s)),
	_execGrade(validateGrade(e)) {}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed),
	_signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
	(void)other;
	std::cout << "can't copy assign Aform, the paperwork is too complicated!"
	<< std::endl;
	return *this;
}

const std::string	AForm::getName() const { return _name; }
bool				AForm::getSignedStat() const { return _signed; }
int					AForm::getSignGrade() const { return _signGrade; }
int					AForm::getExecGrade() const { return _execGrade; }

void AForm::beSigned(const Bureaucrate &b)
{
	if (_signed == true)
		throw AForm::AlreadySignedException();
	if (_signGrade < b.getGrade())
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrate &executor) const
{
	if (_signed == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "<"
		<< f.getName() << ":"
		<< (f.getSignedStat() ? "signed" : "unsigned") << " "
		<< "s:" << f.getSignGrade() << " "
		<< "e:" << f.getExecGrade()
	<< ">";
	return os;
}
