#include "icmd.h"
#include "gamestate.h"

void ICmd::run(GameState &game, const int times) const {
    game.getActivePlayer().changeCurrentBlock('I');
}

