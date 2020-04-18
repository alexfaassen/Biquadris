#include "clockwisecmd.h"
#include "gamestate.h"

void ClockwiseCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().rotateClockwise(times, 1);
}
