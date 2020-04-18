#include "tcmd.h"

void TCmd::run(GameState &game, const int times) const { game.getActivePlayer().changeCurrentBlock('T'); }
