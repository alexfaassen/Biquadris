#include "forceeffect.h"
#include "player.h"

void ForceEffect::notify(const Event currEvent, const int linesCleared) {
	if (currEvent == onTurnStart) {
		player->changeCurrentBlock(newBlock);
		kill();
	}
}
