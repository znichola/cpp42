/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:43:25 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 21:53:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("SC", 145, 137, false), _target("Generic_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("SC", 145, 137, false), _target(target + "_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm("SC",
	other.getExecGrade(),
	other.getSignGrade(),
	other.getSignedStat()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrate &executor) const
{
	AForm::execute(executor);
	std::ofstream file;
	file.exceptions(std::ifstream::badbit);
	file.open(_target.c_str());
	file << "              * *" << std::endl
		<< "           *    *  *" << std::endl
		<< "      *  *    *     *  *" << std::endl
		<< "     *     *    *  *    *" << std::endl
		<< " * *   *    *    *    *   *" << std::endl
		<< " *     *  *    * * .#  *   *" << std::endl
		<< " *   *     * #.  .# *   *" << std::endl
		<< "  *      #.  #: #  * *    *" << std::endl
		<< " *   * *  #. ##        *" << std::endl
		<< "   *        ###" << std::endl
		<< "              ##" << std::endl
		<< "              ##." << std::endl
		<< "              .##:" << std::endl
		<< "              :###" << std::endl
		<< "              ;###" << std::endl
		<< "            ,####." << std::endl
		<< "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\" << std::endl;

	std::cout << "shrubbery has been planted in "
	<< _target << " file." << std::endl;
}
