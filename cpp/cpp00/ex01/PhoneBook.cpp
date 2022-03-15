#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

std::string	truncateString(std::string s) {
	if (s.length() > 10)
	{
		s = s.substr(0, 9);
		s.replace(9, 1, ".");
	}
	return s;
}

void 	PhoneBook::addContact(void) {

	static int 	i = 0;
	std::string	tmp;

	// et attention à ne pas ajouter de NULL (/ spaces ?) !
	std::cout << "First Name : ";
	std::getline(std::cin, tmp);
	this->contacts[i].setFirstName(tmp);
	std::cout << "Last Name : ";
	std::getline(std::cin, tmp);
	this->contacts[i].setLastName(tmp);
	std::cout << "NickName : ";
	std::getline(std::cin, tmp);
	this->contacts[i].setNickName(tmp);
	std::cout << "Phone number : ";
	std::getline(std::cin, tmp);
	this->contacts[i].setPhoneNb(tmp);
	std::cout << "His darkest secret : ";
	std::getline(std::cin, tmp);
	this->contacts[i].setSecret(tmp);

	std::cout << "Your new contact has been saved !" << std::endl;
	i++;
	if (i >= 8)
		i = 0;
}

void	PhoneBook::searchContact(void) {

	int	index = 0;

	if ((this->contacts[0].getFirstName()).empty())
		std::cout << "You don't have any contact, try 'ADD'" << std::endl;
	std::cout << "Here is your contact list :" << std::endl << std::endl;
	std::cout << "____________________________________________" << std::endl;
	std::cout << "|" << std::setw(10) << "     index|" 
					<< std::setw(10) << "first name| "
					<< std::setw(10) << "last name| "
					<< std::setw(10) << "nick name|" << std::endl;
	std::cout << "____________________________________________" << std::endl;
	// ne doit parcourir que jusque le dernier contact set
	for (int i=0; i < 8; i++) {
		std::cout << "|" << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << truncateString(this->contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncateString(this->contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncateString(this->contacts[i].getNickName()) << "|" << std::endl;
		std::cout << "____________________________________________" << std::endl;
	}
	// modifier la condition pour que l'index corresponde à un contact valide
	while (index < 1 || index > 8)
	{
		// pourquoi il boucle si on lui donne un char ? cin = pas protégé ??
		std::cout << "Type the index of the contact you wish to print : " << std::endl;
		std::cin >> index;
		if (index < 1 || index > 8)
			std::cout << "Please enter an index between 1 and 8" << std::endl;
	}
	std::cout << "First Name : " << this->contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name : " << this->contacts[index - 1].getLastName() << std::endl;
	std::cout << "NickName : " << this->contacts[index - 1].getNickName() << std::endl;
	std::cout << "Phone number : " << this->contacts[index - 1].getPhoneNb() << std::endl;
	std::cout << "His darkest secret : " << this->contacts[index - 1].getSecret() << std::endl;
}
