/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:51:18 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 09:43:24 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat pou("Poutoutatix", 150);
	Bureaucrat mac("Macronix", 1);
	Form a38("Le laisser passer A38", 1, 1);
	Form form("Conditions d'utilisation", 150, 150);

	try
	{
		Form form("Le laisser passer A38", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form form("Le laisser passer A38", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		pou.signForm(a38);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	mac.signForm(a38);
	mac.signForm(a38);
	
	std::cout << form << std::endl;
	pou.signForm(form);
	std::cout << form << std::endl;

	return 0;
}