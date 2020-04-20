#include "heavyeffect.h"
#include "player.h"

HeavyEffect::HeavyEffect(bool temp, int numDown) : Effect(temp), numDown{numDown} {
	triggerCommands.emplace_back(Left);
	triggerCommands.emplace_back(Right);
	if (temp) {
		triggerCommands.emplace_back(Down);
		triggerCommands.emplace_back(Clockwise);
		triggerCommands.emplace_back(CounterClockwise);
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
