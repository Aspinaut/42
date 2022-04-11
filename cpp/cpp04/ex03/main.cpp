/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:13:58 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 16:36:58 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

int main()
{
	ICharacter 	*bob;
	AMateria	*mat = new AMateria();

	bob->setName("Bob");
	mat->setType("Ice");
	std::cout << bob->getName() << " tries to get materia... " << std::endl;
	bob->equip(mat);

	return 0;
}