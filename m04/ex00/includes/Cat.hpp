/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:13:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

class Cat
{
private:

public:
// Default constructor
	Cat();

// Copy constructor
	Cat(const Cat &other);

// Destructor
	~Cat();

// Copy assignment operator
	Cat & operator=(const Cat &other);
};

#endif /* CAT_HPP */
