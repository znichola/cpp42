/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:24:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
private:
	std::string	type;
	std::string	sound;

public:
// Default constructor
	Animal();

// Copy constructor
	Animal(const Animal &other);

// Destructor
	~Animal();

// Copy assignment operator
	Animal & operator=(const Animal &other);

	std::string	getType();
	void		makeSound();
};

#endif /* ANIMAL_HPP */
