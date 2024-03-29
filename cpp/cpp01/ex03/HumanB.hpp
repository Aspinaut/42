/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:51:04 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/21 10:46:11 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
	public:

		HumanB(std::string name);
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon &weapon);

	private:

		std::string 	_name;
		Weapon			*_weapon = NULL;
};

#endif