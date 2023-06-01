/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:26:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 19:56:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

#include <stdexcept>
#include <string>

// #include "Form.hpp"
class AForm;

class Bureaucrate
{
private:
	const std::string _name;
	int _grade;
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

	Bureaucrate();
	Bureaucrate(const int grade);
	Bureaucrate(const Bureaucrate &other);
	~Bureaucrate();

	Bureaucrate & operator=(const Bureaucrate &other);

	std::string getName() const;
	int getGrade() const;

	void prompte();
	void demote();

	void signForm(AForm &f);
	void executeForm(const AForm &f);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrate& b);

#endif /* BUREAUCRATE_HPP */
