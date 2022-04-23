/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:46:33 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/23 11:18:56 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;

class RobotomyRequestForm;

class PresidentialPardonForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const &ref);
		~Intern();

		Intern &operator=(Intern const &ref);

		AForm *makeForm(std::string form, std::string target);

		class FormNotFound : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Intern : form not found...");
				}	
		};
};
