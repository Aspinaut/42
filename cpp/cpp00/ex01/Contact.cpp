#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Constructor called" << std::endl;
}

Contact::~Contact(void) {
	std::cout << "Destructor called" << std::endl;
}

void Contact::setFirstName(std::string s) {
	this->firstName = s;
}

void Contact::setLastName(std::string s) {
	this->lastName = s;
}

void Contact::setNickName(std::string s) {
	this->nickName = s;
}

void Contact::setPhoneNb(std::string s) {
	this->phoneNb = s;
}

void Contact::setSecret(std::string s) {
	this->_secret = s;
}

std::string Contact::getFirstName(void) {
	return this->firstName;
}

std::string Contact::getSecret(void) const {
	return this->_secret;
}