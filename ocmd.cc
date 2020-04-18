#include "ocmd.h"
#include "gamestate.h"

void OCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().changeCurrentBlock('O');
}
