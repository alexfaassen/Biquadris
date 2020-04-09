#include "leftcmd.h"

void LeftCmd::run(GameState *game, const int times) const override { game->getActivePlayer().moveBlock(Left, times, 1); }
