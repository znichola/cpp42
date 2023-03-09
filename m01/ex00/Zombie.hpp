/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:35:49 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 01:41:33 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie
{
public:
	Zombie(std::string n);
	~Zombie();
	void	annouce(void);
private:
	std::string	_name;
};
