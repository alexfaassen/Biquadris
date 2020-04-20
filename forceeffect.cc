#include "forceeffect.h"
#include "player.h"

void ForceEffect::notify(const Event currEvent, const int linesCleared) {
	if (currEvent == onTurnStart || currEvent == beforeMove) {
		player->changeCurrentBlock(newBlock);
		kill();
	}
}
