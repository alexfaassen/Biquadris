#include "ocmd.h"

void OCmd::run(GameState &game, const int times) const override { game.getActivePlayer().changeCurrentBlock(new OBlock(game.getActivePlayer().getLevel())); }
