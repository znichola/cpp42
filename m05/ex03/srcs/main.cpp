/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:26:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/08 00:02:55 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrate.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "hello office!" << std::endl;

	Bureaucrate b1(140);
	Bureaucrate b2(89);
	Bureaucrate b3(42);
	Bureaucrate b4(2);

	AForm *f[6];

	Intern intern;

	f[0] = intern.makeForm("robotomy request", "Bender");

	b1.signForm(*f[0]);
	b3.signForm(*f[0]);
	b4.executeForm(*f[0]);

	delete f[0];

	return(0);
}
