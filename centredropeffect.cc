#include "centredropeffect.h"

void CentreDropEffect::notify(const Event currEvent, const int linesCleared) {
	if (currEvent == onTurnEnd) {
		if (linesCleared > 0) {
			blocksSinceClear = 0;
		} else if (blocksSinceClear == 4) {
			player->forceTopTile(new Tile(0, 1, '*', 7, 0));
			blocksSinceClear = 0;
		} else {
			++blocksSinceClear;
		}
	}
}
