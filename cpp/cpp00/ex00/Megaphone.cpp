#include "Megaphone.hpp"

Megaphone::Megaphone(void) {}

Megaphone::~Megaphone(void) {}

void Megaphone::turnOn(std::string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			putchar(toupper(s[i]));
		else
			putchar(s[i]);
	}
	std::cout << std::endl;
}
