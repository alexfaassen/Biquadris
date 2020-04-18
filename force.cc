#include "force.h"
#include <iostream>
#include <fstream>

void Force::run(GameState &game, const int times) const {
	std::istream &in = game.getStream();
	char b;
	in >> b;
	game.getNAP().pushToObservers(new ForceEffect(new Block(b, game.getActivePlayer().isLevel())));
}
