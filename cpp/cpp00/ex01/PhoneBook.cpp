#include "PhoneBook.hpp"
#include <stdlib.h>
#include <unistd.h>

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

std::string	truncateString(std::string s)
{
	if (s.length() > 10)
	{
		s = s.substr(0, 9);
		s.replace(9, 1, ".");
	}
	return s;
}

void 	PhoneBook::addContact(void)
{
	std::string	tmp;

	if (this->size >= 8)
		this->size = 0;
	std::cout << "First Name : ";
	while (tmp.empty())
		std::getline(std::cin, tmp);
	this->contacts[this->size].setFirstName(tmp);

	std::cout << "Last Name : ";
	std::getline(std::cin, tmp);
	while (tmp.empty())
		std::getline(std::cin, tmp);
	this->contacts[this->size].setLastName(tmp);

	std::cout << "NickName : ";
	std::getline(std::cin, tmp);
	while (tmp.empty())
		std::getline(std::cin, tmp);
	this->contacts[this->size].setNickName(tmp);

	std::cout << "Phone number : ";
	std::getline(std::cin, tmp);
	while (tmp.empty())
		std::getline(std::cin, tmp);
	this->contacts[this->size].setPhoneNb(tmp);
	
	std::cout << "His darkest secret : ";
	std::getline(std::cin, tmp);
	while (tmp.empty())
		std::getline(std::cin, tmp);
	this->contacts[this->size].setSecret(tmp);

	std::cout << "Your new contact has been saved !" << std::endl;
	this->size++;
}

void	PhoneBook::searchContact(void)
{
	std::string	rawIndex;
	int			index;

	if ((this->contacts[0].getFirstName()).empty())
	{
		std::cout << "You don't have any contact, try 'ADD'" << std::endl;
		return ;
	}
	std::cout << "Here is your contact list :" << std::endl << std::endl;
	std::cout << "____________________________________________" << std::endl;
	std::cout << "|" << std::setw(10) << "     index|" 
					<< std::setw(10) << "first name| "
					<< std::setw(10) << "last name| "
					<< std::setw(10) << "nick name|" << std::endl;
	std::cout << "____________________________________________" << std::endl;

	for (int i=0; i < this->size; i++) {
		std::cout << "|" << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << truncateString(this->contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncateString(this->contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncateString(this->contacts[i].getNickName()) << "|" << std::endl;
		std::cout << "____________________________________________" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Type the index of the contact you wish to print : " << std::endl;
	std::getline(std::cin, rawIndex);
	index = atoi(rawIndex.c_str());
	while (index < 1 || index > this->size)
	{
		std::cout << "Please enter an index between 1 and " << this->size << std::endl;
		std::getline(std::cin, rawIndex);
		if (std::cin.eof())
			return ;
		index = atoi(rawIndex.c_str());
	}
	std::cout << "First Name : " << this->contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name : " << this->contacts[index - 1].getLastName() << std::endl;
	std::cout << "NickName : " << this->contacts[index - 1].getNickName() << std::endl;
	std::cout << "Phone number : " << this->contacts[index - 1].getPhoneNb() << std::endl;
	std::cout << "His darkest secret : " << this->contacts[index - 1].getSecret() << std::endl;
}

void 	PhoneBook::fill(void)
{
	for (int i=this->size; i < 8; i++)
	{
		this->contacts[i].setFirstName("Justin");
		this->contacts[i].setLastName("Pote");
		this->contacts[i].setNickName("");
		this->contacts[i].setPhoneNb("");
		this->contacts[i].setSecret("");
		this->size++;
	}
}