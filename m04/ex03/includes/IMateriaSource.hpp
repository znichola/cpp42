/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:02:36 by znichola          #+#    #+#             */
/*   Updated: 2023/05/24 01:02:36 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class IMateriaSource
{
private:

public:
// Default constructor
	IMateriaSource();

// Copy constructor
	IMateriaSource(const IMateriaSource &other);

// Destructor
	~IMateriaSource();

// Copy assignment operator
	IMateriaSource & operator=(const IMateriaSource &other);
};

#endif /* IMATERIASOURCE_HPP */
