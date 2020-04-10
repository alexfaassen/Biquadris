#include "restart.h"

void Restart::run(GameState *game, const int times) const override { game->restart(); }
