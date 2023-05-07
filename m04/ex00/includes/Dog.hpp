/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:13:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

class Dog
{
private:

public:
// Default constructor
	Dog();

// Copy constructor
	Dog(const Dog &other);

// Destructor
	~Dog();

// Copy assignment operator
	Dog & operator=(const Dog &other);
};

#endif /* DOG_HPP */
