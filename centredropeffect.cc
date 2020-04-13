#include "centredropeffect.h"

void CentreDropEffect::notify(const Event currEvent, const int linesCleared) override {
	if (currEvent == endTurn) {
		if (linesCleared > 0) {
			blocksSinceCleared = 0;
		} else if (blocksSinceCleared == 4) {
			player->forceTile(new Tile(0, 1, '*', 7, 0));
			blocksSinceCleared = 0;
		} else {
			++blocksSinceCleared;
		}
	}
}
