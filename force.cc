#include "force.h"
#include "forceeffect.h"
#include "gamestate.h"

#include <iostream>
#include <fstream>

void Force::run(GameState &game, const int times) const {
	char b;
	game.readFromStream(b);
	game.getNAP().pushToObservers(new ForceEffect(b));
	if(game.getNAP().getInputState() != END_TURN) game.getNAP().notifyObservers(onSAapplied);
}
