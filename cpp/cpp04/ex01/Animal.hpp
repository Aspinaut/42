/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:15 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/04 16:04:21 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(Animal const &ref);
		virtual ~Animal();

		Animal &operator=(Animal const &ref);

		void setType(std::string type);
		std::string getType() const;
		
		virtual void	makeSound() const;

};

#endif