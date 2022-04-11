/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:37:33 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 16:38:58 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	private:
		std::string	_name;
		AMateria *_materias[MAX];
		int	_index;
		
	public:
		ICharacter();
		// init le destructeur dans le header ??
		virtual ~ICharacter() {};

		virtual std::string const & getName() const = 0;
		virtual void setName(std::string name);
		
		virtual void equip(AMateria* m) = 0;
		// virtual void unequip(int idx) = 0;
		// virtual void use(int idx, ICharacter& target) = 0;
};
