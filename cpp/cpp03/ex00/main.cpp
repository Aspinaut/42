/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 14:12:22 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("b");
	std::cout << "a has now " << a.getEnergyPts() << " energy points." << std::endl;
	b.takeDamage(a.getAttackDmg());
	std::cout << "b has now " << b.getHitPts() << " hit points." << std::endl;
	b.beRepaired(2);
	std::cout << "b has now " << b.getEnergyPts() << " energy points." << std::endl;
	std::cout << "b has now " << b.getHitPts() << " hit points." << std::endl;
	return 0;
}