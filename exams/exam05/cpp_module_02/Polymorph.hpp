#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
using namespace std;

class ASpell;

class Polymorph : public ASpell
{
	public:
		Polymorph();
		Polymorph(const string &name, const string &effects);
		~Polymorph();
	
		virtual ASpell *clone() const;
};
