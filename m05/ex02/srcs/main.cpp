/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:26:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 21:48:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrate.hpp"
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

	f[0] = new ShrubberyCreationForm("ChillValley");
	f[1] = new ShrubberyCreationForm("Foundation");
	f[2] = new RobotomyRequestForm("Vincent");
	f[3] = new RobotomyRequestForm("El_Capitain");
	f[4] = new PresidentialPardonForm("Jo");
	f[5] = new PresidentialPardonForm("Me?");

	for (int i = 0; i < 6; i++)
	{
		b1.signForm(*f[i]);
		b2.executeForm(*f[i]);
		b3.signForm(*f[i]);
		b4.executeForm(*f[i]);
	}



	for (int i = 0; i < 6; i++) delete f[i];
	return(0);
}
