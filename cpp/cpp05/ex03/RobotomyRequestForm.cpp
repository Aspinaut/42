/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:56:34 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 15:04:27 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) : AForm(ref.getName(), ref.getSignGrade(), ref.getSignExec()), _target(ref.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) { this->_target = ref.getTarget(); return *this;}

std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void	RobotomyRequestForm::action() const
{
	std::cout << "~/\\~ BRRRRRXXXXXXXXXZZZZZZZZZZZZZ ~/\\~" << std::endl;
	srand(time(NULL));
	int randNb = rand() % 2 + 1;
	if (randNb == 1)
		std::cout << "Successfully robotomized " << this->_target << "." << std::endl;
	else
		std::cout << "Fail to robotomize " << this->_target << "." << std::endl;
}
