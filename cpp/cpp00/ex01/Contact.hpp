#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact 
{
	public:

		Contact (void);
		~Contact (void);

		void setFirstName(std::string s);
		void setLastName(std::string s);
		void setNickName(std::string s);
		void setPhoneNb(std::string s);
		void setSecret(std::string s);

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getPhoneNb(void) const;
		std::string getSecret(void) const;

	private:
	
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNb;
		std::string _secret;
};

#endif
