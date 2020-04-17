#include "lcmd.h"

void LCmd::run(GameState &game, const int times) const override { game.getActivePlayer().changeCurrentBlock(new Block{'L', game.getActivePlayer().isLevel()}); }
