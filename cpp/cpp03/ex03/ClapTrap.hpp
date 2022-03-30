/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:17:18 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/30 14:16:01 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:

		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &ref);

		void setName(std::string name);
		void setHitPts(int hits);
		void setEnergyPts(int energy);
		void setAttackDmg(int attack);
		std::string	getName() const;
		int	getHitPts() const;
		int	getEnergyPts() const;
		int	getAttackDmg() const;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


	protected:

		std::string _name;
		int	_hitPts;
		int	_energyPts;
		int	_attackDmg;
};

#endif