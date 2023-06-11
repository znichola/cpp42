/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:30:08 by znichola          #+#    #+#             */
/*   Updated: 2023/06/01 21:33:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	RobotomyRequestForm & operator=(const RobotomyRequestForm &other);

	void execute(const Bureaucrate &executor) const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
