/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:30:41 by znichola          #+#    #+#             */
/*   Updated: 2023/07/04 23:32:22 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Wrong number of arguments" << std::endl;
	else
		RPN::solve(std::string(av[1]));

	return(0);
}
