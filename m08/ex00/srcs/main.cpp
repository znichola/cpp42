/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:30:57 by znichola          #+#    #+#             */
/*   Updated: 2023/07/04 16:05:47 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

#include "easyfind.hpp"

int	main(void)
{
	std::cout << "hello easy!" << std::endl;
	{
		std::vector<int> foo(7);

		for (int i = 0; i < 7; i++)
		{
			foo[i] = i * i;
			std::cout << foo[i] << " ";
		}

		std::cout << std::endl;

		std::cout << *easyfind(foo, 16) << std::endl;

		try
		{
			std::cout << *easyfind(foo, 13);
			std::cout << " found 13" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "could not find 13 : " <<  e.what() << std::endl;
		}

	}
	{
		std::deque<int> foo(7);

		for (int i = 0; i < 7; i++)
		{
			foo[i] = i * i;
			std::cout << foo[i] << " ";
		}

		std::cout << std::endl;

		std::cout << *easyfind(foo, 16) << std::endl;

		try
		{
			std::cout << *easyfind(foo, 13);
			std::cout << " found 13" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "could not find 13 : " <<  e.what() << std::endl;
		}

	}
	return(0);
}
