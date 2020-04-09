#include "dropcmd.h"

void DropCmd::run(GameState *game, const int times) const override { game->getActivePlayer().drop(1); }
