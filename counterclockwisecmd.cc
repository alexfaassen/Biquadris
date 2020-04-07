#include "counterclockwisecmd.h"

void CounterClockwiseCmd::run(Player *player, const int times) const override { player->rotateCounterClockwise(times, 1); }
