#include "random.h"
#include "gamestate.h"

#include <fstream>

void Random::run(GameState &game, const int times) const {
	game.getActivePlayer().setFileInput(nullptr);
}

