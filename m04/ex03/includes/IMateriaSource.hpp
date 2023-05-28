/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:02:36 by znichola          #+#    #+#             */
/*   Updated: 2023/05/28 23:34:51 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

class IMateriaSource
{
private:

public:
// Default constructor
	IMateriaSource();

// Copy constructor
	IMateriaSource(const IMateriaSource &other);

// Destructor
	virtual ~IMateriaSource();

// Copy assignment operator
	IMateriaSource & operator=(const IMateriaSource &other);

	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria	*createMateria(std::string const & type) = 0;
};

#endif /* IMATERIASOURCE_HPP */
