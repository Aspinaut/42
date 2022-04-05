/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:13:58 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 14:16:27 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return this->_type; }

void AMateria::setType(std::string type) { this->_type = type; }

AMateria* AMateria::clone() const {}

void AMateria::use(ICharacter& target)
{
	
}