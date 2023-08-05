/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:53:03 by znichola          #+#    #+#             */
/*   Updated: 2023/07/24 16:14:03 by znichola         ###   ########.fr       */
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
	PmergeMe<std::deque<int> >lst("deque");

	if (ac == 2)
	{
		vec.init(std::string(av[1]));
		lst.init(std::string(av[1]));
	}
	else
	{
		vec.init(ac - 1, av + 1);
		lst.init(ac - 1, av + 1);
	}
	if (vec.is_positive() == false)
	{
		std::cout << "Error: entered non positive number" << std::endl;
		return 1;
	}
	
	try
	{
		vec.before();
		vec.timeSort();
		lst.timeSort();
		vec.after();
		vec.timeReport();
		lst.timeReport();
	}
	catch (...)
	{
		std::cout << "Error: something went wrong.";
		return (1);
	}
	return(0);
}
