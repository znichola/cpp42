/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:30:39 by znichola          #+#    #+#             */
/*   Updated: 2023/07/04 12:45:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	uint32_t x = std::clock();
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;

	switch (x % 3)
	{
	case 0:
		std::cout << "generated A" << std::endl;
		return new A;
	case 1:
		std::cout << "generated B" << std::endl;
		return new B;
	case 2:
		std::cout << "generated C" << std::endl;
		return new C;
	}

	std::cout << "something went wrong with the randome" << std::endl;
	return new A;
}

void identify(Base *p)
{
	if (A *obj = dynamic_cast<A *>(p))
		std::cout << "it's A" <<std::endl;
	else if (B *obj = dynamic_cast<B *>(p))
		std::cout << "it's B" <<std::endl;
	else if (C *obj = dynamic_cast<C *>(p))
		std::cout << "it's C" <<std::endl;
	else
		std::cout << "no idea what type" <<std::endl;
}

void identify(Base &p)
{

	try
	{
		A &obj = dynamic_cast<A &>(p);
		std::cout << "it's A" <<std::endl;
		(void)obj;
	}
	catch(const std::bad_cast) 	{}
	try
	{
		B &obj = dynamic_cast<B &>(p);
		std::cout << "it's B" <<std::endl;
		(void)obj;
	}
	catch(const std::bad_cast) 	{}
	try
	{
		C &obj = dynamic_cast<C &>(p);
		std::cout << "it's C" <<std::endl;
		(void)obj;
	}
	catch(const std::bad_cast) 	{}


	(void)p;
}

int	main(void)
{
	std::cout << "hello real!" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		Base * foo = generate();
		identify(foo);
		identify(*foo);
		std::cout << std::endl;
		delete foo;
	}
	return(0);
}
