#pragma once
#include <iostream>
#include <string>
using namespace std;

class ATarget;

class ASpell
{
	public:
		ASpell();
		ASpell(const string &name, const string &effects);
		virtual ~ASpell();
	
		const string getName() const;
		const string getEffects() const;

		virtual ASpell *clone() const = 0;

		void launch(ATarget const &ref) const;

	protected:
		const string name;
		const string effects;

};
