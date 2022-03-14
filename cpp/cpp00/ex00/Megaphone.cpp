#include "Megaphone.hpp"

Megaphone::Megaphone(void) {}

Megaphone::~Megaphone(void) {}

void Megaphone::turnOn(std::string s) {
	for (int i = 0; i < s.length(); i++) {
		putchar(toupper(s[i]));
	}
	std::cout << std::endl;
}
