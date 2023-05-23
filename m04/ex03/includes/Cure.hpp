/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:17 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 23:57:17 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

class Cure
{
private:

public:
// Default constructor
	Cure();

// Copy constructor
	Cure(const Cure &other);

// Destructor
	~Cure();

// Copy assignment operator
	Cure & operator=(const Cure &other);
};

#endif /* CURE_HPP */
