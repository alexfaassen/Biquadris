#include "heavyeffect.h"

void HeavyEffect::notify(const Event currEvent, const int linesCleared) override {
	if (currEvent == afterMove) player->moveBlock(Down, numDown, 0);
}
