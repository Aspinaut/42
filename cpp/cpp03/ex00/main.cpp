/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/30 11:53:17 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	std::cout << "A has now " << a.getEnergyPts() << " energy points." << std::endl;
	b.takeDamage(a.getAttackDmg());
	std::cout << "B has now " << b.getHitPts() << " hit points." << std::endl;
	b.beRepaired(2);
	std::cout << "B has now " << b.getEnergyPts() << " energy points." << std::endl;
	std::cout << "B has now " << b.getHitPts() << " hit points." << std::endl;
	
	ClapTrap c = b;
	c.setName("C");
	std::cout << "And here is " <<  c.getName() << ", the copy of B." << std::endl;
	return 0;
}