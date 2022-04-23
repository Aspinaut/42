/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:56:34 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/21 11:02:01 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &ref) { (void)ref; }

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &ref) { (void)ref; return *this; }

static AForm *NewShrubberyForm(std::string target)
{
	AForm *shrub = new ShrubberyCreationForm(target); 
	return shrub;
}

static AForm *NewRobotomyForm(std::string target)
{
	AForm *robot = new RobotomyRequestForm(target); 
	return robot;
}

static AForm *NewPresidentialForm(std::string target)
{
	AForm *pres = new PresidentialPardonForm(target); 
	return pres;
}

AForm *Intern::makeForm(std::string formType, std::string targetName)
{
	AForm	*(*fct[3])(std::string target) = { NewShrubberyForm, NewRobotomyForm, NewPresidentialForm };
	std::string types[3] = {"shrubbery creation form", "robotomy request form", "presidential pardon form"};

	for (int i=0; i < 3; i++)
	{
		if (formType == types[i])
		{
			std::cout << "Intern creates " << types[i] << std::endl;
			return fct[i](targetName);
		}
	}
	throw Intern::FormNotFound();
	return NULL;
}
