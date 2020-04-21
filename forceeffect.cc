#include "forceeffect.h"
#include "player.h"

void ForceEffect::notify(const Event currEvent, const Move currMove) {
	if (currEvent == onTurnStart || currEvent == beforeMove || currEvent == onSAapplied) {
		player->changeCurrentBlock(newBlock);
		kill();
	}
}
