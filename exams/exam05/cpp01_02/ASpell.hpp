#pragma once
#include <iostream>
#include <string>
using namespace std;

class ATarget;

class ASpell
{
	public:
		ASpell(const string &name, const string &effects);
		virtual ~ASpell();
	
		const string getName() const;
		const string getEffects() const;

		virtual const ASpell *clone(ASpell const &ref) = 0;

		void launch(ATarget const &ref) const;

	protected:
		const string name;
		const string effects;

};
