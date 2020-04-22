#include "dropcmd.h"
#include "gamestate.h"

void DropCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().drop(times, true);
}

