/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:52:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/11 14:14:31 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, int const sg, int const se) : _name(name), _signGrade(sg), _signExec(se) { ErrorThrower(sg, se); this->_signed = false; }

AForm::AForm(AForm const &ref) : _name(ref.getName()), _signGrade(ref.getSignGrade()), _signExec(ref.getSignExec()) { this->_signed = ref.getSigned(); }

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &ref)
{
	this->_signed = ref.getSigned();
	return *this;
}

std::string const AForm::getName() const { return this->_name; }

bool	AForm::getSigned() const { return this->_signed; }

void	AForm::beSigned(Bureaucrat const &ref)
{
	if (this->getSigned() == false && ref.getGrade() <= this->getSignGrade())
	{
		this->_signed = true;
	}
}

int AForm::getSignGrade() const { return this->_signGrade; }

int AForm::getSignExec() const { return this->_signExec; }

void	AForm::ErrorThrower(int sg, int se) const
{
	if (sg > 150 || se > 150)
		throw AForm::GradeTooLowException();
	else if (sg < 1 || se < 1)
		throw AForm::GradeTooHighException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw AForm::NotSigned();
	if (executor.getGrade() > this->getSignExec())
		throw Bureaucrat::GradeTooLowException();
	
}

std::ostream &operator<<(std::ostream &out, AForm const &ref)
{
	out << ref.getName() << ", form with signGrade " << ref.getSignGrade() << " and with signExec " << ref.getSignExec() << ". ";
	if (ref.getSigned())
		out << "It is signed.";
	else
		out << "It is not signed.";
	return out;
}

