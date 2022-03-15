#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class PhoneBook {

	public:

		Contact contacts[8];

		PhoneBook (void);
		~PhoneBook (void);

		void 	addContact (void);
		void	searchContact (void);
};

#endif
