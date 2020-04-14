#include "observer.h"

bool Observer::isAlive() { return alive; }

void Observer::kill() { delete this; }

void Observer::attach(const Player *newPlayer) {
	if (player) delete player;
	player = newPlayer;
}
