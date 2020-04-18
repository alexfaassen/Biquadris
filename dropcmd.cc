#include "dropcmd.h"

void DropCmd::run(GameState &game, const int times) const { game.getActivePlayer().drop(1); }
