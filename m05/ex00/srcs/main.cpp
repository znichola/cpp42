/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:26:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 15:17:10 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "Bureaucrate.hpp"

static void test(Bureaucrate &b);
std::ostream& operator<<(std::ostream& os, const Bureaucrate& b);

int	main(void)
{
	std::cout << "hello office!" << std::endl;

	Bureaucrate a(150);
	Bureaucrate b(1);
	Bureaucrate c(42);

	test(a);
	test(b);
	test(c);

	std::cout << "instansing invalid grades" << std::endl << "<" << std::endl;
	try
	{
		Bureaucrate f(0);
		std::cout << "badly instansed " << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrate f(151);
		std::cout << "badly instansed " << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrate f(31);
	std::cout << ">" << std::endl
	<< "correctly instatiated bureucrate :" << f << std::endl;
	return(0);
}

static void test(Bureaucrate &b)
{
	std::cout << "<" << std::endl;
	std::cout << "testing: " << b << std::endl;
	try
	{
		std::cout << "  demote:" << std::endl;
		b.demote();
		b.prompte();
		std::cout << " prompte:" << std::endl;
		b.prompte();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << " result: " << b << std::endl;
	std::cout << ">" << std::endl;

}

std::ostream &operator<<(std::ostream &os, const Bureaucrate &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
