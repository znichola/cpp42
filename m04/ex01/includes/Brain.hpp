/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:56:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 21:58:43 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
protected:
	std::string	ideas[100];

public:
// Default constructor
	Brain();

// Copy constructor
	Brain(const Brain &other);

// Destructor
	~Brain();

// Copy assignment operator
	Brain & operator=(const Brain &other);

// Methods
	void		printIdeas(unsigned int how_many) const;
	std::string	getIdea(unsigned int idex) const;
};

#endif /* BRAIN_HPP */
