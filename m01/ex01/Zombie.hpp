/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:35:49 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 01:41:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie
{
public:
	Zombie();
	~Zombie();
	void	annouce(void);
	void	Name(std::string name);
private:
	std::string	_name;
};
