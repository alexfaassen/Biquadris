#include "downcmd.h"
#include "gamestate.h"

void DownCmd::run(GameState &game, const int times) const {
    game.getActivePlayer().moveBlock(Down, times); 
}
