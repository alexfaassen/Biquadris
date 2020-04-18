#include "heavy.h"

void Heavy::run(GameState &game, const int times) const override { game.getNAP().pushToObservers(new HeavyEffect(2)); }
