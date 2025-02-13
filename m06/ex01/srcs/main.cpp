/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:38:01 by znichola          #+#    #+#             */
/*   Updated: 2023/07/04 12:41:56 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::cout << "hello serializer!" << std::endl;

	Data d = {42, 89};

	std::cout << d;
	std::cout << *Serializer::deserialize(Serializer::serialize(&d));

	return 0;
}
