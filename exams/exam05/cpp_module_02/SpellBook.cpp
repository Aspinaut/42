#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		spells.insert(pair<string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(string const &ref)
{
	map<string, ASpell *>::iterator it = spells.find(ref);
	spells.erase(ref);
}

ASpell* SpellBook::createSpell(string const &ref)
{
	map<string, ASpell *>::iterator it = spells.find(ref);
	if (it != spells.end())
		return spells[ref];
	return NULL;
}
