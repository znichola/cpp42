/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:35:56 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 01:41:33 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "iostream"

Zombie::Zombie(std::string n)
{
	this->_name = n;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": has dieeddd.." << std::endl;
}

void Zombie::annouce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
