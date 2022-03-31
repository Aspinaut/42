/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 10:59:26 by vmasse           ###   ########.fr       */
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
	
	
	ClapTrap c;
	c = b;
	c.setName("C");
	std::cout << "Here is " <<  c.getName() << ", the copy of B by assignment. He has " << c.getEnergyPts() << " energy points, " << c.getHitPts() << " hit points and " << c.getAttackDmg() << " attack damage." << std::endl;
	
	ClapTrap d(c);
	d.setName("D");
	std::cout << "And finally " <<  d.getName() << ", the copy of C by copy constructor. He has " << d.getEnergyPts() << " energy points, " << d.getHitPts() << " hit points and " << d.getAttackDmg() << " attack damage." << std::endl;

	return 0;
}