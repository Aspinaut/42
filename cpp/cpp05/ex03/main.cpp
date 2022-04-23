/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:51:18 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/23 12:54:28 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	{
		Bureaucrat pou("Poutoutatix", 150);
		Bureaucrat mac("Macronix", 1);
		ShrubberyCreationForm form("Elysee");
		
		// SHRUBBERY CREATION 
		
		std::cout << form << std::endl;

		try
		{
			mac.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		mac.signForm(form);

		try
		{
			pou.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		mac.executeForm(form);
	}

	// ROBOTOMY REQUEST

	{
		Bureaucrat pou("Poutoutatix", 150);
		Bureaucrat mac("Macronix", 1);
		RobotomyRequestForm form("Elysee");

		mac.signForm(form);
		mac.executeForm(form);
	}

	// PRESIDENTIAL PARDN

	{
		Bureaucrat pou("Poutoutatix", 150);
		Bureaucrat mac("Macronix", 1);
		PresidentialPardonForm form("Elysee");

		try
		{
			mac.executeForm(form);
			mac.signForm(form);
			pou.executeForm(form);
			mac.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	
	}

	// INTERN

	{
		Intern someRandomIntern;
		AForm *rrf;

		try
		{
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			rrf = someRandomIntern.makeForm("shrubbery creation form", "Sylvebarbe");
			std::cout << *rrf << std::endl;
			delete rrf;
			rrf = someRandomIntern.makeForm("robotomy request form", "Bender");
			std::cout << *rrf << std::endl;
			delete rrf;
			rrf = someRandomIntern.makeForm("presidential pardon form", "Macronix");
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	return 0;
}
