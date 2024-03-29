/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:35:07 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/19 16:52:02 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << this->_name << ": Gneeeeeeee..." << std::endl; 
}

Zombie::Zombie( void )
{
	std::cout << "A zombie is alive !" << std::endl;
}


Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << "The zombie " << _name << " is alive !" << std::endl;
}


Zombie::~Zombie( void )
{
	std::cout << "The zombie " << _name << " has been killed..." << std::endl;
}
