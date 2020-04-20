#include "heavyeffect.h"
#include "player.h"

void HeavyEffect::notify(const Event currEvent, const int linesCleared) {
	if (currEvent == afterMove) {
		int moved = player->moveBlock(Down, numDown, false);
		if(moved < numDown){
			player->drop(1, false);
			player->endTurn();
		}
	} else if (currEvent == onTurnEnd) {
		update();
	}
}
