#include "downcmd.h"

void DownCmd::run(GameState *game, const int times) const override { game->getActivePlayer().moveBlock(Down, times, 1); }
