#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
using namespace std;

class Fwoosh : public ASpell
{
	public:
		Fwoosh(const string &name, const string &effects);
		~Fwoosh();
	
		const string getName() const;
		const string getEffects() const;

		void launch(ATarget const &ref) const;

	protected:
		const string name;
		const string effects;

};
