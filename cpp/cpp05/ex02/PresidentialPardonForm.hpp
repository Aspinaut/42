/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:46:33 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 10:18:56 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : virtual public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &ref);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &ref);

		std::string getTarget() const;

		void		execute(Bureaucrat const &executor) const;
};