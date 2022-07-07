#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
using namespace std;

class ASpell;

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		Fwoosh(const string &name, const string &effects);
		~Fwoosh();
	
		virtual ASpell *clone() const;
};
