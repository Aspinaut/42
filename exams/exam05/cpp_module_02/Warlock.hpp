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

		const string &getName() const;
		void setTitle(const string &title);
		const string &getTitle() const;

		void learnSpell(ASpell const *spell);
		void forgetSpell(string const spellName);
		void launchSpell(string const spellName, ATarget const &ref);

	private:
		const string 			_name;
		string 					_title;
		map<string, ASpell *> 	_spells;
		SpellBook 				book;

		Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
};
