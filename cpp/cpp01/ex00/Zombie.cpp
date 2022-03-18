/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:35:07 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/18 15:51:08 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << this->_name << ": Gneeeeeeee..." << std::endl; 
}

Zombie::Zombie( void ) {}

Zombie::~Zombie( void )
{
	std::cout << "The zombie " << this->_name << " has been killed..." << std::endl;
}

Zombie* Zombie::newZombie( std::string name )
{
	Zombie *zombie = new Zombie;

	zombie->_name = name;
	return zombie;
}

void Zombie::randomChump( std::string name )
{
	Zombie	zombie = Zombie();

	zombie._name = name;
}