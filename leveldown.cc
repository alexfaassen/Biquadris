#include "leveldown.h"

void LevelDown::run(GameState &game, const int times) const override { game.getActivePlayer().changeLevel(-1 * times); }
