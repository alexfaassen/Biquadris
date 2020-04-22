#include "levelup.h"
#include "gamestate.h"

void LevelUp::run(GameState &game, const int times) const {
    game.getActivePlayer().incLevel(times);
}

