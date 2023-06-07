/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:48:18 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 19:40:29 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <time.h>
#include <sstream>
#include <iostream>

#include <string>
#include <stdexcept>

#include "Bureaucrate.hpp"

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

	int validateGrade(int grade);

protected:
	std::string getID();

public:
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class NotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	AForm();
	AForm(const int s, const int e);
	AForm(const std::string t, const int s, const int e, bool stat);
	AForm(const AForm &other);

	virtual ~AForm();

	AForm & operator=(const AForm &other);

	std::string getName() const;
	bool getSignedStat() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrate &b);
	virtual void execute(const Bureaucrate &executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif /* AFORM_HPP */
