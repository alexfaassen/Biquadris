#include "lcmd.h"

void LCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().changeCurrentBlock('L');
}
