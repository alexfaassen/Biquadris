#include "scmd.h"
#include "gamestate.h"

void SCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().changeCurrentBlock('S');
}

