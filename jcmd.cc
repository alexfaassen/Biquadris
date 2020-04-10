#include "jcmd.h"

void JCmd::run(GameState &game, const int times) const override { game.getActivePlayer().changeCurrentBlock(new JBlock(game.getActivePlayer().getLevel())); }
