/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:51:18 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 10:14:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat pou("Poutoutatix", 150);
	Bureaucrat mac("Macronix", 1);
	ShrubberyCreationForm form("le laisser passer a38");
	
	// SHRUBBERY CREATION 
	
	std::cout << form << std::endl;
	form.execute(mac);
	mac.signForm(form);

	try
	{
		form.execute(pou);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	form.execute(mac);

	// ROBOTOMY

	return 0;
}