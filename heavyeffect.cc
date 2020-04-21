#include "heavyeffect.h"
#include "player.h"

HeavyEffect::HeavyEffect(bool temp, int numDown) : Effect(temp), numDown{numDown} {
	triggerMoves.emplace_back(mLeft);
	triggerMoves.emplace_back(mRight);
}

bool HeavyEffect::isTrigger(const Move m) const {
	for (auto p : triggerMoves) {
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
		kill();
	}
}
