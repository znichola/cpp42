/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:02:55 by znichola          #+#    #+#             */
/*   Updated: 2023/03/06 14:33:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	addContact(Contact contact);
		int	getSize(void) const;
		Contact	getContact(int id) const;
		void	displayContact(int id) const;
	private:
		int	_size;
		Contact	_contacts[0];
		_shuffleBack(void);
};

#endif

