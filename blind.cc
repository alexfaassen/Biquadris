#include "blind.h"

void Blind::run(GameState &game, const int times) const { game.getNAP().pushToObservers(new BlindEffect()); }
