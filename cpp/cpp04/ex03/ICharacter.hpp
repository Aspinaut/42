/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:37:33 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 14:49:10 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "AMateria.hpp"

class ICharacter
{
	private:
		std::string	_name;
		AMateria *materias[MAX];
		
	public:
		ICharacter();
		virtual ~ICharacter() {};

		virtual std::string const & getName() const = 0;
		virtual void setName(std::string name);
		
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
