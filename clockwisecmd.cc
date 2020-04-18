#include "clockwisecmd.h"

void ClockwiseCmd::run(GameState &game, const int times) const { game.getActivePlayer().rotateClockWise(times, 1); }
