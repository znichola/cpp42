/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 02:03:55 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 02:31:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

// A string variable initialized to "HI THIS IS BRAIN".
	std::string	hi = "HI THIS IS BRAIN";

// stringPTR: A pointer to the string.
	std::string	*stringPRT = &hi;

// stringREF: A reference to the string.
	std::string	&stringREF = hi;


// The memory address of the string variable.
	std::cout << "address  hi: " << &hi << std::endl;

// The memory address held by stringPTR.
	std::cout << "address ptr: " << stringPRT << std::endl;

// The memory address held by stringREF.
	std::cout << "address ref: " << &stringREF << std::endl;


// The value of the string variable.
	std::cout << "  value  hi: " << hi << std::endl;

// The value pointed to by stringPTR.
	std::cout << "  value ptr: " << *stringPRT << std::endl;

// The value pointed to by stringREF.
	std::cout << "  value ref: " << stringREF << std::endl;

	return 0;
}
