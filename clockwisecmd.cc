#include "clockwisecmd.h"

void ClockwiseCmd::run(Player &player, const int times) const override { player.rotateClockwise(times, 1); }
