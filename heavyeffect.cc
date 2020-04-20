#include "heavyeffect.h"
#include "player.h"

HeavyEffect::HeavyEffect(bool temp, int numDown) : Effect(temp), numDown{numDown} {
	triggerCommands.emplace_back(mLeft);
	triggerCommands.emplace_back(mRight);
	if (temp) {
		triggerCommands.emplace_back(mDown);
		triggerCommands.emplace_back(mClockwise);
		triggerCommands.emplace_back(mCounterClockwise);
	}
}

bool HeavyEffect::isTrigger(const Move m) const {
	for (auto p : triggerCommands) {
		if (p == m) return true;
	}
	return false;
}

void HeavyEffect::notify(const Event currEvent, const Move currMove) {
	if (currEvent == afterMove && isTrigger(currMove)) {
		int moved = player->moveBlock(Down, numDown, false);
		if(moved < numDown){
			player->drop(1, false);
		}
	} else if (currEvent == onTurnEnd) {
		update();
	}
}
