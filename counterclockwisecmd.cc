#include "counterclockwisecmd.h"

void CounterClockwiseCmd::run(GameState &game, const int times) const { game.getActivePlayer().rotateCounterClockWise(times, 1); }
