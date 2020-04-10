#include "zcmd.h"

void ZCmd::run(GameState &game, const int times) const override { game.getActivePlayer().changeCurrentBlock(new ZBlock(game.getActivePlayer().getLevel())); }
