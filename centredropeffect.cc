#include "centredropeffect.h"

void CentreDropEffect::notify(const Event currEvent, const int linesCleared) override {
	if (currEvent == onTurnEnd) {
		if (blocksSinceCleared == 4) {
			player->forceTopTile(new Tile(0, 1, '*', 7, 0));
			blocksSinceCleared = 0;
		} else {
			++blocksSinceCleared;
		}
	} else if (currEvent == onLinesCleared) {
		blocksSinceCleared = 0;
	}
}
