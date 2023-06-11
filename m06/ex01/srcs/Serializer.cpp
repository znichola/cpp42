/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:38:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/11 13:54:33 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer::~Serializer() {}
Serializer &Serializer::operator=(const Serializer &other)
{ (void)other; return *this; }

uintptr_t Serializer::serializer(Data *ptr)
{
	return static_cast<Data>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return nullptr;
}
