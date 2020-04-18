#include "icmd.h"

void ICmd::run(GameState &game, const int times) const { game.getActivePlayer().changeCurrentBlock(new Block('I', game.getActivePlayer().isLevel())); }
