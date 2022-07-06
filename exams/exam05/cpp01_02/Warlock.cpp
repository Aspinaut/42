#include "Warlock.hpp"

Warlock::Warlock(const string &n, const string &t) : _name(n), _title(t)
{
	cout << _name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock()
{
	cout << _name << ": My job here is done !" << endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (find(this->_spells.begin(), this->_spells.end(), spell._name) != this->_spells.end())
	{
		this->_spells.insert(spell._name, spell);
	}
}

void Warlock::forgetSpell(string spellName)
{
	if (find(this->_spells.begin(), this->_spells.end(), spellName) != this->_spells.end())
	{
		delete this->_spells;
	}
}

void Warlock::launchSpell(string spellName, ATarget &ref)
{
	if (find(this->_spells.begin(), this->_spells.end(), spellName) != this->_spells.end())
	{
		this->_spells.launch(ref);
	}
}

void Warlock::introduce() const
{
	cout << _name << ": I am " << _name << ", " << _title << "!" << endl;
}

void Warlock::setTitle(const string &t) { _title = t; }

string const Warlock::getTitle() const { return _title; }
string const Warlock::getName() const { return _name; }
