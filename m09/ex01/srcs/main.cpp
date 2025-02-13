/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:30:41 by znichola          #+#    #+#             */
/*   Updated: 2023/07/23 13:06:57 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int	main(int ac, char **av)
{
	std::string input;

	if (ac == 1)
	{
		std::cerr << "No arguments given." << std::endl;
	}
	else
	{
		for (int i = 1; i < ac; i++)
			input += std::string(av[i]) + " ";
	}	

	RPN::solve(input);
	return(0);
}
