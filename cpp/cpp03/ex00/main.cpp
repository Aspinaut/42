/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 13:52:04 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClavTrap.hpp"

int main()
{
	ClavTrap a("A");
	ClavTrap b("B");

	a.attack("b");
	std::cout << "a has now " << a.getEnergyPts() << " energy points." << std::endl;
	b.takeDamage(a.getAttackDmg());
	std::cout << "b has now " << b.getHitPts() << " hit points." << std::endl;
	b.beRepaired(2);
	std::cout << "b has now " << b.getEnergyPts() << " energy points." << std::endl;
	std::cout << "b has now " << b.getHitPts() << " hit points." << std::endl;
	return 0;
}