/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:14:15 by znichola          #+#    #+#             */
/*   Updated: 2023/03/15 02:37:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);

	std::string	get_fName(void) const;
	void		set_fName(std::string str);

	std::string	get_lName(void) const;
	void		set_lName(std::string str);

	std::string	get_nName(void) const;
	void		set_nName(std::string str);

	std::string	get_phoneNumber(void) const;
	void		set_phoneNumber(std::string str);

	std::string	get_secret(void) const;
	void		set_secret(std::string str);

private:
	std::string	_fName;
	std::string	_lName;
	std::string	_nName;
	std::string	_phoneNumber;
	std::string	_secret;
};

#endif
