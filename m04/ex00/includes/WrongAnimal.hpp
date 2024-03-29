/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:37:57 by znichola          #+#    #+#             */
/*   Updated: 2023/05/22 10:31:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
protected:
	std::string	type;

public:
// Default constructor
	WrongAnimal();

// Copy constructor
	WrongAnimal(const WrongAnimal &other);

// Destructor
	~WrongAnimal();

// Copy assignment operator
	WrongAnimal & operator=(const WrongAnimal &other);

// Methods
	std::string		getType(void) const;
	void			makeSound(void) const;
};

#endif /* WRONGANIMAL_HPP */
