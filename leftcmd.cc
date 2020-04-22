#include "leftcmd.h"
#include "gamestate.h"

void LeftCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().moveBlock(Left, times, true);
}

