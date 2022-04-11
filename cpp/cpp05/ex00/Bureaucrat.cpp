/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:52:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/11 13:06:56 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) { ErrorThrower(grade); }

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : _name(ref.getName()), _grade(ref.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ref)
{
	// this->setName(ref.getName());
	this->setGrade(ref.getGrade());
	return *this;
}

std::string const Bureaucrat::getName() const { return this->_name; }

// void	 	Bureaucrat::setName(std::string const name) { this->_name = name; }

void	Bureaucrat::setGrade(int grade) { ErrorThrower(grade); this->_grade = grade; }

int		Bureaucrat::getGrade() const { return this->_grade; }

void	Bureaucrat::upGrade()
{
	ErrorThrower(this->_grade - 1);
	this->_grade--;
}

void	Bureaucrat::downGrade()
{
	ErrorThrower(this->_grade + 1);
	this->_grade++;
}

void	Bureaucrat::ErrorThrower(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "." << std::endl;
	return out;
}