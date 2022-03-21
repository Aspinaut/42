/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:09:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/21 18:15:05 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() {}

Karen::~Karen() {}

void Karen::_debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Karen::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Karen::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Karen::_error( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Karen::complain( std::string level )
{
	const std::string optionsKaren[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int choice = -1;

	for (int i = 0; i < 4; i++)
		if (optionsKaren[i] == level)
			choice = i;

	switch(choice)
	{
		case 0:
			_debug();
			break;

		case 1:
			_info();
			break;
		
		case 2:
			_warning();
			break;
		
		case 3:
			_error();
			break;
		
		default:
			break;
	}
}
