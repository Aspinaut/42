/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:54:42 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/01 11:05:19 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
	this->_index = 0;
}

Brain::Brain(Brain const &ref)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i=0; i < MAX; i++)
		this->_ideas[i] = ref._ideas[i];
}

Brain::~Brain() { std::cout << "Brain destructor called." << std::endl; }

Brain	&Brain::operator=(Brain const &ref)
{
	std::cout << "Brain copy assignment called." << std::endl;
	for (int i=0; i < MAX; i++)
		this->_ideas[i] = ref._ideas[i];
	return *this;
}

void	Brain::setIdea(std::string idea)
{
	this->_ideas[(this->_index)++] = idea;
	if (this->_index >= MAX)
		this->_index = 0;
}

std::string Brain::getIdea(unsigned int index) const
{
	if (index >= MAX)
	{
		std::cout << "Please insert an invalid index... (between 0 and 99)" << std::endl;
		return "";
	}
	return this->_ideas[index];
}

void	Brain::fillIdeas()
{
	for (int i = this->_index; i < MAX; i++)
		this->_ideas[i] = "Some idea";
}
