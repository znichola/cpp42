/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:57:10 by znichola          #+#    #+#             */
/*   Updated: 2023/03/06 14:29:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_size = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::addContact(Contact contact)
{
	if (this->_size >= 8)
	{
		//need to call the shuffleback
	}
	this->_contacts[_size] = contact;
	this->_size += 1;	
	return ;
}

