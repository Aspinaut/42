#include "PhoneBook.hpp"

int	main()
{
	PhoneBook 	phonebook;
	std::string	cmd;

	std::cout << "Hey, I'm your favorite phonebook !" << std::endl;
	std::cout << "Type one of these options : ADD, SEARCH, EXIT" << std::endl;
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else if (cmd == "EXIT")
			return (0);
		else if (cmd == "FILL")
			phonebook.fill();
		else
			std::cout << "Type one of these options : ADD, SEARCH, EXIT" << std::endl;
	}
	return 0;
}
