/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:51:18 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 09:42:21 by vmasse           ###   ########.fr       */
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

	std::cout << lowBob << std::endl;
	lowBob.upGrade();
	std::cout << lowBob << std::endl;
	lowBob.downGrade();
	try
	{
		lowBob.downGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << highBob << std::endl;
	highBob.downGrade();
	std::cout << highBob << std::endl;
	highBob.upGrade();
	try
	{
		highBob.upGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		highBob.setGrade(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	highBob.setGrade(5);
	std::cout << highBob << std::endl;

	return 0;
}