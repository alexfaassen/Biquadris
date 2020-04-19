#include "rightcmd.h"
#include "gamestate.h"

void RightCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().moveBlock(Right, times, true);
}
