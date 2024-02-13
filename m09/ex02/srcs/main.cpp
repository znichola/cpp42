/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:53:03 by znichola          #+#    #+#             */
/*   Updated: 2023/08/09 13:40:11 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "give me some arguments" << std::endl;
		return 1;
	}
	PmergeMe<std::vector<int> >vec("vector");
	PmergeMe<std::deque<int> >deq("deque");

	if (ac == 2)
	{
		vec.init(std::string(av[1]));
		deq.init(std::string(av[1]));
	}
	else
	{
		vec.init(ac - 1, av + 1);
		deq.init(ac - 1, av + 1);
	}
	if (vec.is_positive() == false)
	{
		std::cout << "Error: don't support negative numbers" << std::endl;
		return 1;
	}

	try
	{
		vec.before();
		vec.timeSort();
		deq.timeSort();
		vec.after();
		vec.timeReport();
		deq.timeReport();
		if (!vec.is_sorted() || !deq.is_sorted())
		{
			std::cout << "not sorted!";
			return 1;
		}
	}
	catch (...)
	{
		std::cout << "Error: something went wrong.";
		return (1);
	}
	return(0);
}
