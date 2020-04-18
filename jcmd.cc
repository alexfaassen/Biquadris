#include "jcmd.h"

void JCmd::run(GameState &game, const int times) const { game.getActivePlayer().changeCurrentBlock(new Block('J', game.getActivePlayer().isLevel())); }
