#include "tcmd.h"

void TCmd::run(GameState &game, const int times) const override { game.getActivePlayer().changeCurrentBlock(new TBlock(game.getActivePlayer().getLevel())); }
