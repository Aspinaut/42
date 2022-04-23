/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:44:35 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/11 14:47:48 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool	_signed;
		int const _signGrade;		
		int const _signExec;
	
	public:
		AForm(std::string const name, int const sg, int const se);
		AForm(AForm const &ref);
		virtual ~AForm();

		AForm &operator=(AForm const &ref);

		std::string const	getName() const;
		bool	getSigned() const;
		void	beSigned(Bureaucrat const &ref);
		int 	getSignGrade() const;
		int 	getSignExec() const;
		void	ErrorThrower(int sg, int se) const;
		void	execute(Bureaucrat const &executor) const;
		virtual void action() const = 0;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form : grade too low...");
				}	
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form : grade too high...");
				}	
		};

		class NotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form is not signed...");
				}		
		};
		
		class AlreadySigned : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form is already signed...");
				}		
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &ref);
