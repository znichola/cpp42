/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:26:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 15:03:56 by znichola         ###   ########.fr       */
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

	test(a);
	test(b);

	std::cout << "instansing invalid grades" << std::endl;

	Bureaucrate *foo;
	try
	{
		foo = new Bureaucrate(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		foo = new Bureaucrate(151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "adress of badly instatiated bureucrate :" << foo << std::endl;
	foo = new Bureaucrate(31);
	std::cout << "adress of correctly instatiated bureucrate :" << foo << std::endl;
	return(0);
}

static void test(Bureaucrate &b)
{
	std::cout << "////////////////////////////" << std::endl;
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
}

std::ostream &operator<<(std::ostream &os, const Bureaucrate &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
