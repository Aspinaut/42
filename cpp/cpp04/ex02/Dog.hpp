/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:15 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/15 15:07:58 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"

class Dog : public AAnimal
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

		virtual void	makeSound() const;
};

#endif