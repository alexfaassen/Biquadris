#include "random.h"
#include "gamestate.h"

#include <fstream>

void Random::run(GameState &game, const int times) const {
	if (game.getActivePlayer().isLevel() == 3 || game.getActivePlayer().isLevel() == 4) game.getActivePlayer().setFileInput(NULL);
}
