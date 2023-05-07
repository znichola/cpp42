/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:13:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
private:

public:
// Default constructor
	Animal();

// Copy constructor
	Animal(const Animal &other);

// Destructor
	~Animal();

// Copy assignment operator
	Animal & operator=(const Animal &other);
};

#endif /* ANIMAL_HPP */
