/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:02:29 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/30 21:17:05 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
	
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		
		void whoAmI();
		void attack(std::string const &target);

		std::string getName() const;
		void setName(std::string const &name);

	private:

		std::string _name;
};

#endif