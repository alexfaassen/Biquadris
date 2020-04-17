#include "heavyeffect.h"

void HeavyEffect::notify(const Event currEvent, const int clearedLines) override {
	if (currEvent == afterMove){
		int moved = player->moveBlock(Down, numDown, 0);
		if(moved < numDown){
			player->endTurn();
		}
	}
}
