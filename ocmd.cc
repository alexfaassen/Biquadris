#include "ocmd.h"

void OCmd::run(GameState &game, const int times) const { game.getActivePlayer().changeCurrentBlock(new Block('O', game.getActivePlayer().isLevel())); }
