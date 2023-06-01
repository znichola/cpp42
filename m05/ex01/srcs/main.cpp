/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:26:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 17:15:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrate.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "hello office!" << std::endl;

	Bureaucrate b1(42);
	Bureaucrate b2(89);

	Form f1(61, 40);
	Form f2(42, 42);
	Form f3(21, 90);

	b1.signForm(f1);
	b1.signForm(f1);
	b2.signForm(f2);
	b1.signForm(f2);
	b2.signForm(f3);
	b1.signForm(f3);

	std::cout << "form tests: " << std::endl;

	try
	{
		Form f4(-1, 12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f5(160, 12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return(0);
}
