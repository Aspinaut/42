#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(const string &n, const string &e) : ASpell(n, e) {}

Fwoosh::~Fwoosh() {}

ASpell *Fwoosh::clone() const { return new Fwoosh(); }
