/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:57:10 by znichola          #+#    #+#             */
/*   Updated: 2023/03/08 20:48:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	this->_size = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::GetNewContact(void)
{
	std::string	buff;
	int			n = 0;
	if (this->_size >= 8)
	{
		std::cout << "your crazy\n";
		this->_shuffleBack();
	}
	while (n <= 4)
	{
		// restart:
		if (n == 0)
			std::cout << "First Name: ";
		else if (n == 1)
			std::cout << "Last Name: ";
		else if (n == 2)
			std::cout << "Nick Name: ";
		else if (n == 3)
			std::cout << "Phone Number: ";
		else if (n == 4)
			std::cout << "Secret: ";

		if (!std::getline(std::cin, buff))
			return ;
		if (buff.size() == 0)
		{
			std::cout << "can't be empty, filling with something random" << std::endl;
			this->_fillRandomData(n);
			// goto restart;
		}
		else
		{
			if (n == 0)
			this->_contacts[this->_size].set_fName(buff);
			else if (n == 1)
				this->_contacts[this->_size].set_lName(buff);
			else if (n == 2)
				this->_contacts[this->_size].set_nName(buff);
			else if (n == 3)
				this->_contacts[this->_size].set_phoneNumber(buff);
			else if (n == 4)
				this->_contacts[this->_size].set_secret(buff);
		}

		buff.clear();
		n++;
	}
	this->_size += 1;
	return ;
}

void	PhoneBook::DisplayContacts(void) const
{
	std::cout	<< std::string (47, '-') << std::endl;
	std::cout	<< "  |"
		<< this->_clippedStr("first name") << "|"
		<< this->_clippedStr("second name") << "|"
		<< this->_clippedStr("nick name") << "|"
		<< this->_clippedStr("phone number") << "|" << std::endl;
	std::cout	<< std::string (47, '-') << std::endl;
	for (int i = 0; i < this->_size; i++)
	{
		std::cout	<< " " << i+1 << "|"
			<< this->_clippedStr(this->_contacts[i].get_fName()) << "|"
			<< this->_clippedStr(this->_contacts[i].get_lName()) << "|"
			<< this->_clippedStr(this->_contacts[i].get_nName()) << "|"
			<< this->_clippedStr(this->_contacts[i].get_phoneNumber()) << "|" << std::endl;
	}
	// std::cout	<< std::string (47, '-') << std::endl;
	return ;
}

void PhoneBook::GetContactId(void)
{
	bool		flag = true;
	std::string	buff;

	restart:
	std::cout << std::endl << "Select Contact: ";
	if (!std::getline(std::cin, buff))
		return ;
	if (this->DisplayContactInfo(std::atoi(buff.c_str())))
	{
		if (flag)
		{
			std::cout << "selction out of range";
		}
		else
		{
			std::cout << "quitting" << std::endl;
			return ;
		}
		flag = false;
		goto restart;
	}
	return ;
}

bool	PhoneBook::DisplayContactInfo(int id) const
{
	id--;
	if (id < 0 || id >= this->_size)
		return (true);
	std::cout //<< std::endl
		<< this->_clippedStr("First")		<< " : " << this->_contacts[id].get_fName() << std::endl
		<< this->_clippedStr("Second")		<< " : " << this->_contacts[id].get_lName() << std::endl
		<< this->_clippedStr("Nickname")	<< " : " << this->_contacts[id].get_nName() << std::endl
		<< this->_clippedStr("Phone nbr")	<< " : " << this->_contacts[id].get_phoneNumber() << std::endl
		<< this->_clippedStr("Secret")		<< " : " << this->_contacts[id].get_secret() << std::endl;
	return (false);
}

Contact *PhoneBook::_retNextContact(void)
{
	return (&this->_contacts[this->_size]);
}

std::string PhoneBook::_clippedStr(std::string str) const
{
	if (str.size() > 10)
	{
		str.resize(9);
		return (str + "." );
	}
	else
	{
		return (std::string (10 - str.size(), ' ') + str);
	}
}

void PhoneBook::_fillRandomData(int n)
{
		if (n == 0)
		{
			std::string lst[] ={"Emily", "Isabella", "Emma", "Ava", "Madison", "Jacob", "Michael", "Ethan", "Joshua", "Daniel"};
			this->_contacts[this->_size].set_fName(lst[std::rand() % 10]);
		}
		else if (n == 1)
		{
			std::string lst[] = {"Castaneda", "Miles", "Underwood", "Vega", "Bray", "Cunningham", "Knight", "Phelps", "Sloan", "Sweeney"};
			this->_contacts[this->_size].set_lName(lst[std::rand() % 10]);
		}
		else if (n == 2)
		{
			std::string lst[] = {"Whisker Biscuit", "Sugar Booger", "Captain Crunchwrap", "Fuzzy Pickle", "Sir Snotsalot", "Muffin Maniac", "Princess Bubblegumdrop", "Donut Destroyer", "The Great Guffaw", "Count Snuggles"};
			this->_contacts[this->_size].set_nName(lst[std::rand() % 10]);
		}
		else if (n == 3)
		{
			std::string lst[] = {"+49 238 71560", "+1 (816) 452-3098", "+44 20 3695 8330", "+81 3-5467-6293", "+33 1 85 14 11 74", "+55 11 3053-6611", "+61 3 9021 0826", "+86 10 6502 6616"};
			this->_contacts[this->_size].set_phoneNumber(lst[std::rand() % 8]);
		}
		else if (n == 4)
		{
			std::string lst[] = {"I love to travel and have been to over 10 countries!",
								"I am a huge animal lover and have two cats and a dog.",
								"I am a foodie and love trying new restaurants and cuisines.",
								"I play the guitar and have been in a band for the past year.",
								"I am a coffee addict and can't start my day without a strong cup of joe!"};
			this->_contacts[this->_size].set_secret(lst[std::rand() % 5]);
		}
}

void PhoneBook::_shuffleBack(void)
{
	for (int i = 1; i < 8; i++)
		this->_contacts[i - 1] = this->_contacts[i];
	this->_size--;
}
