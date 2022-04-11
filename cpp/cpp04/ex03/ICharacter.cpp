/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:37:03 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 16:21:31 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter() : _index(0) {}

std::string const &ICharacter::getName() const { return this->_name; }

void ICharacter::setName(std::string name) { this->_name = name; }

void ICharacter::equip(AMateria* m)
{
	this->_materias[this->_index++] = m;
}

// void ICharacter::unequip(int idx)
// {

// }

// void ICharacter::use(int idx, ICharacter& target)
// {

// }
