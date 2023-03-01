/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:34:01 by znichola          #+#    #+#             */
/*   Updated: 2023/03/01 20:17:19 by znichola         ###   ########.fr       */
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
		std::string s(av[i]);
		std::cout << s.size();
		for (int i = 0; i < s.size(); i++)
		{
			wchar_t	c = s[i];
			std::cout << c.toupper();
		}
	//	for (int i = 0; av[i].size(); i++
	//	std::cout << std::toupper((av[i])) << std::endl;
	}		
}
