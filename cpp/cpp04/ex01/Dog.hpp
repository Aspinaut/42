/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:15 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/01 10:53:26 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(Dog const &ref);
		~Dog();

		Dog &operator=(Dog const &ref);

		void	setBrain(Brain *Brain);
		Brain *getBrain() const;

		void	makeSound() const;
};

#endif