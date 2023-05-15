/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:56:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:56:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
private:

public:
// Default constructor
	Brain();

// Copy constructor
	Brain(const Brain &other);

// Destructor
	~Brain();

// Copy assignment operator
	Brain & operator=(const Brain &other);
};

#endif /* BRAIN_HPP */
