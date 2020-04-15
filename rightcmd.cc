#include "rightcmd.h"

void RightCmd::run(GameState &game, const int times) const override { game.getActivePlayer().moveBlock(Right, times, 1); }
