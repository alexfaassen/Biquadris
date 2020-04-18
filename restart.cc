#include "restart.h"
#include "gamestate.h"

void Restart::run(GameState &game, const int times) const {
    game.restart();
}
