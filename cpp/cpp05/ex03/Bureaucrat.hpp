/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:51:49 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 21:10:41 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int			_grade;
	
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &ref);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &ref);

		std::string	const getName() const;
		void		setGrade(int grade);
		int			getGrade() const;

		void	upGrade();
		void	downGrade();
		void 	ErrorThrower(int grade) const;
		void	signForm(AForm &f) const;
		void	executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat : grade too high...");
				}		
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat : grade too low...");
				}	
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &ref);
