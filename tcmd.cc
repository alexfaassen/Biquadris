#include "tcmd.h"

void TCmd::run(GameState &game, const int times) const { game.getActivePlayer().changeCurrentBlock(new Block('T', game.getActivePlayer().isLevel())); }
