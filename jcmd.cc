#include "jcmd.h"
#include "gamestate.h"

void JCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().changeCurrentBlock('J');
}

