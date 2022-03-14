#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "Contact.hpp"

class Phonebook {

	private:

	public:

		Contact contacts[8];

		Phonebook (void);
		~Phonebook (void);

		void 	addContact (void);
		Contact *searchContact (void);
};

#endif
