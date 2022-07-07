#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
using namespace std;

class ASpell;

class Fireball : public ASpell
{
	public:
		Fireball();
		Fireball(const string &name, const string &effects);
		~Fireball();
	
		virtual ASpell *clone() const;
};
