#include "Fwoosh.hpp"

Fwoosh::Fwoosh(const string &n, const string &e) : ASpell() {}

Fwoosh::~Fwoosh() {}

void Fwoosh::launch(ATarget const &ref) const
{
	ref.getHitBySpell(*this);
}

string const Fwoosh::getEffects() const { return effects; }
string const Fwoosh::getName() const { return name; }
