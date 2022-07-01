#include "Warlock.hpp"

Warlock::Warlock(const string n, const string t) : _name(n), _title(t)
{
	cout << _name << ": This looks like another boring day." << endl;
}

Warlock::Warlock(const Warlock &rhs) : _name(rhs._name), _title(rhs._title)
{
	cout << _name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock()
{
	cout << _name << ": My job here is done !" << endl;
}

void Warlock::introduce() const
{
	cout << _name << ": I am " << _name << ", " << _title << "!" << endl;
}

void Warlock::setTitle(const string t) { _title = t; }
void Warlock::setName(const string n) { _name = n; }


string Warlock::getTitle() const { return _title; }
string Warlock::getName() const { return _name; }
