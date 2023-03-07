/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:02:55 by znichola          #+#    #+#             */
/*   Updated: 2023/03/07 22:05:20 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	AddContact(Contact contact);
	void	DisplayContacts(void) const;
	void	DisplayContactInfo(int id) const;

private:
	int		_size;
	Contact	_contacts[8];
	// void	_shuffleBack(void);
};

#endif
