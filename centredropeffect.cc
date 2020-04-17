#include "centredropeffect.h"

void CentreDropEffect::notify(const Event currEvent, const int linesCleared) {
	if (currEvent == onTurnEnd) {
		if (linesCleared > 0) {
			blocksSinceClear = 0;
		} else if (blocksSinceClear == 4) {
			player->forceTopTile('*', 5);
			blocksSinceClear = 0;
		} else {
			++blocksSinceClear;
		}
	} else if (currEvent == onLinesCleared) {
		blocksSinceCleared = 0;
	}
}
