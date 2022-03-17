#include "Megaphone.hpp"

Megaphone::Megaphone(void) {}

Megaphone::~Megaphone(void) {}

void Megaphone::turnOn(std::string s)
{
	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			putwchar(toupper(s[i]));
		else
			putwchar(s[i]);
	}
	putwchar('\n');
}
