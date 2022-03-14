#include "Megaphone.hpp"

Megaphone::Megaphone(void) {
	std::cout << "Constructor called" << std::endl;
}

Megaphone::~Megaphone(void) {
	std::cout << "Destructor called" << std::endl;
}

void Megaphone::turnOn(std::string s) {
	for (int i = 0; i < s.length(); i++) {
		putchar(toupper(s[i]));
	}
	std::cout << std::endl;
}