#include "observer.h"
#include "player.h"

bool Observer::isAlive() const { return alive; }

void Observer::kill() { delete this; }

void Observer::attach(Player* const newPlayer) { player = newPlayer; }
