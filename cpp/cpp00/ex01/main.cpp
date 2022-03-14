#include "PhoneBook.hpp"

int	main(int argc, char *argv[])
{
	Phonebook 	phonebook;
	std::string	cmd;

	std::cout << "Hey, I'm your favorite phonebook !" << std::endl;
	while (std::getline(std::cin, cmd))
	{
		std::cout << "Type one of these options : ADD, SEARCH, EXIT" << std::endl;
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else if (cmd == "EXIT")
			return (0);
	}
	return 0;
}
