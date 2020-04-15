#include "ocmd.h"

void OCmd::run(GameState &game, const int times) const override { game.getActivePlayer().changeCurrentBlock(new Block('O', game.getActivePlayer().isLevel())); }
