/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:12:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 14:48:43 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>
# define MAX 4
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const &type);
		virtual ~AMateria();

		std::string const &getType() const;
		void setType(std::string type);
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
