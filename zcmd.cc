#include "zcmd.h"

void ZCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().changeCurrentBlock('Z');
}
