#include "sacommand.h"

void SACommand::execute(GameState &game, const int times) const {	
	run(game, times);
	game.getActivePlayer.endTurn();
	if (needClean) game.cleanup();
}
