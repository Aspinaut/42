/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:51:04 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/20 09:01:43 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:

		HumanA(std::string name, Weapon weapon);
		~HumanA();

		void	attack();
	
	private:

		std::string _name;
		Weapon		_weapon;
};

#endif