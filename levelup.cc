#include "levelup.h"

void LevelUp::run(GameState &game, const int times) const override { game.getActivePlayer().incLevel(times); }
