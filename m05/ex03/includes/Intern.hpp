/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:08:57 by znichola          #+#    #+#             */
/*   Updated: 2023/06/08 11:19:23 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <stdexcept>

# include "AForm.hpp"

// the intern is an abstract factory

class Intern
{
public:
	class NonExistantForm : public std::exception
	{
		public:
			const char *what() const throw();
	};

	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern & operator=(const Intern &other);

	AForm *makeForm(const std::string form, const std::string target) const;
};

#endif /* INTERN_HPP */
