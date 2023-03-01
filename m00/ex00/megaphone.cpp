/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:34:01 by znichola          #+#    #+#             */
/*   Updated: 2023/03/01 22:58:19 by znichola         ###   ########.fr       */
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
		auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());
		std::wstring str = L"yes";
		std::string s(av[i]);
		//std::wstring foo(av[i]);
		//std::wstring foo = av[i];
		auto& b = std::use_facet<std::ctype<char>>(std::locale());
		std::string foo(av[i]);
		b.toupper(&foo[0], &foo[0] + foo.size());
		
		f.toupper(&str[0], &str[0] + str.size());
		
		//std::wcout << str << std::endl;
		std::cout << foo << std::endl;
	}		
}
