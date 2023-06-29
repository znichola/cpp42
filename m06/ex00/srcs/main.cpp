/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:35:33 by znichola          #+#    #+#             */
/*   Updated: 2023/06/29 22:14:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "give me some argument" << std::endl;
	else
		ScalarConverter::convert(std::string(av[1]));
	return(0);
}
