#include "blind.h"

void Blind::run(GameState &game, const int times) const override { game.getNAP().pushToObservers(new BlindEffect()); }
