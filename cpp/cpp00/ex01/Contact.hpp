#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {

	private:
		std::string _secret;

	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNb;

		Contact (void);
		~Contact (void);

		void setFirstName(std::string s);
		void setLastName(std::string s);
		void setNickName(std::string s);
		void setPhoneNb(std::string s);
		void setSecret(std::string s);

		std::string getFirstName(void);
		std::string getSecret(void) const;

};

#endif