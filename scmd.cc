#include "scmd.h"

void SCmd::run(GameState &game, const int times) const { game.getActivePlayer().changeCurrentBlock(new Block('S', game.getActivePlayer().isLevel())); }
