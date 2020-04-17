#include "forceeffect.h"

void ForceEffect::notify(const Event currEvent, const int linesCleared) override {
	if (currEvent == beforeMove) player->changeCurrentBlock(newBlock);
}
