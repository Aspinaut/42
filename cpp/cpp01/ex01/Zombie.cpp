/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:35:07 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/19 17:05:18 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void ) const
{
	std::cout << this->_name << ": Gneeeeeeee..." << std::endl; 
}

Zombie::Zombie( void )
{
	std::cout << "A zombie is alive !" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << "The zombie " << _name << " is alive !" << std::endl;
}


Zombie::~Zombie( void )
{
	std::cout << "The zombie " << _name << " has been killed..." << std::endl;
}
