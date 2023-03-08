/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:02:55 by znichola          #+#    #+#             */
/*   Updated: 2023/03/08 20:41:06 by znichola         ###   ########.fr       */
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

	void	GetNewContact(void);
	void	DisplayContacts(void) const;
	void	GetContactId(void);
	bool	DisplayContactInfo(int id) const;

private:
	int			_size;
	Contact		_contacts[8];
	Contact		*_retNextContact(void);
	std::string	_clippedStr(std::string str) const;
	void		_fillRandomData(int n);
	void		_shuffleBack(void);
};

#endif
