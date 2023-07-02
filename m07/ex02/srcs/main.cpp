/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:20:46 by znichola          #+#    #+#             */
/*   Updated: 2023/07/02 12:15:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Array.hpp"

int	main(void)
{
	std::cout << "hello array!" << std::endl;

	{
		Array<int> foo(10);

		for (int i = 0; i < 10; i++)
			foo[i] = clock();

		Array<int> bar(foo);

		foo[2] = 42;

		for (int i = 0; i < 10; i++)
			std::cout << foo[i] << " ";

		std::cout << std::endl;

		for (int i = 0; i < 10; i++)
			std::cout << foo[i] << " ";

		std::cout << "size: " << foo.size() << " " << foo.size() << std::endl;
	}
	{
		Array<std::string> foo(5);

		foo[0] = "bar";
		foo[1] = "bizz";
		foo[2] = "bang";
		foo[3] = "fizz";
		foo[4] = "buzz";

		Array<std::string> bar = foo;

		foo[0] = "something new";
		foo[1] = "to check";
		foo[2] = "it's a proper deep copy";

		for (int i = 0; i < 5; i++)
			std::cout << foo[i] << " ";

		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
			std::cout << bar[i] << " ";

		std::cout << std::endl;

		std::cout << "size: " << foo.size() << " " << foo.size() << std::endl;
	}
	{
		Array<float> foo(3);

		try
		{
			foo[99] = 3.14;
			std::cout << "no exception thrown" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "we threw: "<< e.what() << std::endl;
		}

		Array<float> bar;

		try
		{
			bar[0] = 3.14;
			std::cout << "no exception thrown" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "we threw: "<< e.what() << std::endl;
		}

	}


	return(0);
}
