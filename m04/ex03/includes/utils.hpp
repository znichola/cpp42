/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:54:46 by znichola          #+#    #+#             */
/*   Updated: 2023/05/30 11:58:40 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "ICharacter.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const ICharacter& character);

#endif
