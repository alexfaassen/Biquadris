#include "force.h"
#include "forceeffect.h"
#include "gamestate.h"

#include <iostream>
#include <fstream>
#include <stdio.h>

void Force::run(GameState &game, const int times) const {
	char b;
	game.readFromStream(b);
	cout << "force::run New Block: " << b <<endl;
	game.getNAP().pushToObservers(new ForceEffect(b));
	if(game.getNAP().getInputState() != END_TURN) game.getNAP().notifyObservers(onSAapplied);
}
