/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:13:58 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 14:48:16 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

int main()
{
	ICharacter 	*bob;
	AMateria	*mat;

	bob->setName("Bob");
	mat->setType("Ice");
	std::cout << bob->getName() << " tries to get materia... " << std::endl;
	bob->equip(mat);

	return 0;
}