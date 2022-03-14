#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

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

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

std::string Contact::getNickName(void) const {
	return this->_nickName;
}

std::string Contact::getPhoneNb(void) const {
	return this->_phoneNb;
}

std::string Contact::getSecret(void) const {
	return this->_secret;
}
