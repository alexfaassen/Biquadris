#include "zcmd.h"

void ZCmd::run(GameState &game, const int times) const override { game.getActivePlayer().changeCurrentBlock(new Block{'Z', game.getActivePlayer().isLevel()}); }
