/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:53:03 by znichola          #+#    #+#             */
/*   Updated: 2023/07/13 17:56:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::cout << "hello PmergeMe!" << std::endl;
	if (ac < 2)
	{
		std::cout << "give me some arguments" << std::endl;
		return 1;
	}	
	PmergeMe<std::vector<int> >vec;
	PmergeMe<std::deque<int> >lst;

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
	vec.before();
	vec.timeSort();
	lst.timeSort();
	vec.after();

	vec.timeReport("vector");
	lst.timeReport("deque");	
	
	
	return(0);
}
