#include "heavy.h"
#include "heavyeffect.h"
#include "gamestate.h"

void Heavy::run(GameState &game, const int times) const { game.getNAP().pushToObservers(new HeavyEffect(2)); }
