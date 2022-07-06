#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
#include "ASpell.hpp"

class ASpell;
class ATarget;

class Warlock
{
	public:
		Warlock(const string &name, const string &title);
		~Warlock();
	
		void introduce() const;

		const string getName() const;
		void setTitle(const string &title);
		const string getTitle() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(string spellName);
		void launchSpell(string spellName, ATarget const &ref);

	private:
		const string 			_name;
		string 					_title;
		map<string, ASpell *> 	_spells;

		Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
};
