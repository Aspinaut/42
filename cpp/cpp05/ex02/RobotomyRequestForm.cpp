/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:56:34 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 10:16:37 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) : AForm(ref.getName(), ref.getSignGrade(), ref.getSignExec()), _target(ref.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) { this->_target = ref.getTarget(); return *this;}

std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::string	shrub = 
		"     ccee88oo          \n"
		"  C8O8O8Q8PoOb o8oo    \n"
		" dOB69QO8PdUOpugoO9bD  \n"
		"CgggbU8OU qOp qOdoUOdcb\n"
		"   6OuU  /p u gcoUodpP \n"
		"      \\\\//  /douUP   \n"
		"        \\\\////       \n"
		"         |||/\\        \n"
		"         |||\\/        \n"
		"         |||||         \n"
		"  	...\\//||||\\....   \n";
	
	if (this->getSigned() == false)
	{
		std::cout << "Form is not signed and cannot be executed" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getSignExec())
		throw AForm::GradeTooLowException();
	std::ofstream ofs((this->_target + "_shrubbery").c_str());
	if (!ofs.is_open())
	{
		std::cout << "Fail to open the output file" << std::endl;
		return ;
	}
	ofs << shrub;
	ofs.close();
	std::cout << "Successfully executed " << this->getName() << std::endl;
}
