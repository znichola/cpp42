/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:08:57 by znichola          #+#    #+#             */
/*   Updated: 2023/06/07 23:17:30 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

// the intern is an abstract factory

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern & operator=(const Intern &other);

	AForm *makeForm(const std::string form, const std::string target) const;
};

#endif /* INTERN_HPP */
