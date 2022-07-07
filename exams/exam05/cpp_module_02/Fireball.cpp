#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::Fireball(const string &n, const string &e) : ASpell(n, e) {}

Fireball::~Fireball() {}

ASpell *Fireball::clone() const { return new Fireball(); }
