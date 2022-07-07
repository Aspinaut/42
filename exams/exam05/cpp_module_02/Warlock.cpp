#include "Warlock.hpp"

Warlock::Warlock(const string &n, const string &t) : _name(n), _title(t)
{
	book = new SpellBook();
	cout << _name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock()
{
	cout << _name << ": My job here is done !" << endl;
}

void Warlock::learnSpell(ASpell const *spell)
{
	book.learnSpell();
}

void Warlock::forgetSpell(string const spellName)
{
	book.forgetSpell();
}

void Warlock::launchSpell(string const spellName, ATarget const &ref)
{
	ASpell* spell = _spells[spellName];
	if (spell)
		spell->launch(ref);
}

void Warlock::introduce() const
{
	cout << _name << ": I am " << _name << ", " << _title << "!" << endl;
}

void Warlock::setTitle(const string &t) { _title = t; }

string const &Warlock::getTitle() const { return _title; }
string const &Warlock::getName() const { return _name; }
