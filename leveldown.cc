#include "leveldown.h"
#include "gamestate.h"

void LevelDown::run(GameState &game, const int times) const {
    game.getActivePlayer().incLevel(-1 * times);
}

