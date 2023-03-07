/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonepook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:57:10 by znichola          #+#    #+#             */
/*   Updated: 2023/03/07 22:05:31 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	this->_size = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::AddContact(Contact contact)
{
	if (this->_size >= 8)
	{
		//need to call the shuffleback
	}
	this->_contacts[_size] = contact;
	this->_size += 1;
	std::cout << "adding contact" << this->_size - 1 << std::endl;
	return ;
}

void	PhoneBook::DisplayContacts(void) const
{
	std::cout << "a list of contacts\n 0. Jack\n1. Jill" << std::endl;
	return ;
}

void	PhoneBook::DisplayContactInfo(int id) const
{
	std::cout << "showing" << id << "info" << std::endl;
	return ;
}
