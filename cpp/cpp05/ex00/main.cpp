/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:51:18 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/11 10:39:57 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat lowBob("Bob the lowest", 150);
	Bureaucrat highBob("Bob the highest", 1);

	try
	{
		Bureaucrat bobTooHigh("Bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bobTooLow("Bob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << lowBob;
	lowBob.upGrade();
	std::cout << lowBob;
	lowBob.downGrade();
	try
	{
		lowBob.downGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << highBob;
	highBob.downGrade();
	std::cout << highBob;
	highBob.upGrade();
	try
	{
		highBob.upGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}