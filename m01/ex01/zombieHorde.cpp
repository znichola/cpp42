/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:38:44 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 01:59:46 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <sstream>

static	std::string	int_to_str(int n);

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*Zeds = new Zombie[N];

	for (int i = 0; i < N; i++)
		Zeds[i].Name(name + int_to_str(i));
	return Zeds;
}

static	std::string	int_to_str(int n)
{
	std::ostringstream	ostr;
	ostr << n;
	return ostr.str();
}
