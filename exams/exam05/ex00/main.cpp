#include "Warlock.hpp"

int main()
{
	Warlock bob("Bob", "blabla");
	Warlock jim("Jim", "blabla");

	jim.introduce();
	bob.introduce();
	bob = jim;
	bob.introduce();
	return 0;
}
