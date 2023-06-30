/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:35:33 by znichola          #+#    #+#             */
/*   Updated: 2023/06/30 10:02:29 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "you failed to give me valid input " << std::endl;
	else
		ScalarConverter::convert(std::string(av[1]));
	return(0);
}
