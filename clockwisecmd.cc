#include "clockwisecmd.h"

void ClockwiseCmd::run(GameState &game, const int times) const override { game.getActivePlayer().rotateClockwise(times, 1); }
