/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:12:58 by znichola          #+#    #+#             */
/*   Updated: 2023/03/10 10:24:38 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <string>

class Harl
{
public:
	Harl(/* args */);
	~Harl();

	void	complain(std::string level) const;
private:
	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;
};

#endif
