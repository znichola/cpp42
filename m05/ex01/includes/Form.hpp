/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:48:18 by znichola          #+#    #+#             */
/*   Updated: 2023/06/10 11:07:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <stdexcept>

#include "Bureaucrate.hpp"

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

	int validateGrade(int grade);

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

	Form();
	Form(const int s, const int e);
	Form(const Form &other);

	~Form();

	Form & operator=(const Form &other);

	const std::string getName() const;
	bool getSignedStat() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrate &b);
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif /* FORM_HPP */
