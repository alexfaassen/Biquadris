#include "counterclockwisecmd.h"

void CounterClockwiseCmd::run(GameState *game, const int times) const override { game->getActivePlayer().rotateCounterClockwise(times, 1); }
