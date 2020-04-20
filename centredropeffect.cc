#include "centredropeffect.h"
#include "player.h"

void CentreDropEffect::notify(const Event currEvent, const Move currMove) {
	if (currEvent == onTurnEnd) {
		if (blocksSinceClear == 2) {
			player->forceTopTile('*', 5);
			blocksSinceClear = 0;
		} else {
			++blocksSinceClear;
		}
	} else if (currEvent == onLinesCleared) {
		blocksSinceClear = 0;
	}
}
