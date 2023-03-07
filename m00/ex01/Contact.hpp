/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:14:15 by znichola          #+#    #+#             */
/*   Updated: 2023/03/06 14:32:47 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

//typdef std::string t_string;

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string	getFirstname(void) const;
		bool		setFirstname(std::string name);
		std::string	getLastname;
		bool		setLastname;
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_secret;
}

#endif

