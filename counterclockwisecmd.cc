#include "counterclockwisecmd.h"
#include "gamestate.h"

void CounterClockwiseCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().rotateCounterClockwise(times, true);
}
