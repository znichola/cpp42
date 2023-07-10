/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:53:03 by znichola          #+#    #+#             */
/*   Updated: 2023/07/10 17:09:57 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::cout << "hello PmergeMe!" << std::endl;

	PmergeMe<std::vector<int> >foo("1 2 3 4 41 42 -8       69      420");

	foo.print();	
	return(0);
}
