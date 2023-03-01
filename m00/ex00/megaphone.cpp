/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:34:01 by znichola          #+#    #+#             */
/*   Updated: 2023/03/01 23:01:06 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}	
	for (int i = 1; i < ac; i++)
	{
		auto& f = std::use_facet<std::ctype<char>>(std::locale());
		std::string str(av[i]);
		f.toupper(&str[0], &str[0] + str.size());
		std::cout << str;
	}
	std::cout << std::endl;
}
