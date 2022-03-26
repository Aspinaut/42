/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:17:18 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 14:33:23 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:

		ClapTrap();
		ClapTrap(const std::string name);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		const std::string	getName();
		int	getHitPts();
		int	getEnergyPts();
		int	getAttackDmg();

	private:

		const std::string _name;
		int	_hitPts;
		int	_energyPts;
		int	_attackDmg;
};

#endif