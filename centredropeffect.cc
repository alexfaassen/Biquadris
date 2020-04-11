#include "centredropeffect.h"

void CentreDropEffect::notify(const Event currEvent, const int linesCleared) override {
	if (currEvent == afterMove) {
		if (linesCleared != 0) {
			blocksSinceCleared = 0;
		} else if (blocksSinceCleared == 4) {
			// TODO centre drop
		} else {
			++blocksSinceCleared;
		}
	}
}
