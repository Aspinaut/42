/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:09:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/24 13:02:46 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::_debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	const std::string optionsHarl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void   (Harl::*fct[4])(void) = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };

	int choice = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == optionsHarl[i])
			choice = i;
	}

	switch(choice)
	{
		_debug_:
		case 0:
			(this->*(fct[0]))();
			goto _info_;

		_info_:
		case 1:
			(this->*(fct[1]))();
			goto _warning_;

		_warning_:
		case 2:
			(this->*(fct[2]))();
			goto _error_;

		_error_:
		case 3:
			(this->*(fct[3]))();
			break;

		default:
			std::cout << "I don't know what you're talking about." << std::endl;
			break;
	}
}
