/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:53:03 by znichola          #+#    #+#             */
/*   Updated: 2023/07/12 06:10:56 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::cout << "hello PmergeMe!" << std::endl;
	if (ac < 2)
	{
		std::cout << "give me some arguments" << std::endl;
		return 1;
	}	
	PmergeMe<std::vector<int> >foo;

	if (ac == 2)	
		foo.init(std::string(av[1]));
	else
		foo.init(ac - 1, av + 1);

	foo.before();
	foo.after();	
	foo.time("vector");
	return(0);
}
