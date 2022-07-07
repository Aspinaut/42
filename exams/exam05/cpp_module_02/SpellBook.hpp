#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
using namespace std;

class ASpell;

class SpellBook
{
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(string const &ref);
		ASpell* createSpell(string const &ref);

	private:
		map<string, ASpell *> spells;
		SpellBook(SpellBook const &ref);
		SpellBook &operator=(SpellBook const &ref);
};