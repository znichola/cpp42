/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:55:56 by znichola          #+#    #+#             */
/*   Updated: 2023/03/08 13:20:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::get_fName(void) const
{
	return (this->_fName);
}

void Contact::set_fName(std::string str)
{
	this->_fName = str;
}

std::string Contact::get_lName(void) const
{
	return (this->_lName);
}

void Contact::set_lName(std::string str)
{
	this->_lName = str;
}

std::string Contact::get_nName(void) const
{
	return (this->_nName);
}

void Contact::set_nName(std::string str)
{
	this->_nName = str;
}

std::string Contact::get_phoneNumber(void) const
{
	return (this->_phoneNumber);
}

void Contact::set_phoneNumber(std::string str)
{
	this->_phoneNumber = str;
}

std::string Contact::get_secret(void) const
{
	return (this->_secret);
}

void Contact::set_secret(std::string str)
{
	this->_secret = str;
}
