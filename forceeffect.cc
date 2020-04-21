#include "forceeffect.h"
#include "player.h"
#include <iostream>

using namespace std;

void ForceEffect::notify(const Event currEvent, const Move currMove) {
	if (currEvent == onTurnStart || currEvent == beforeMove || currEvent == onSAapplied) {
		cout << "forceeffect notifioed" << endl;
		player->changeCurrentBlock(newBlock);
		kill();
	}
}
