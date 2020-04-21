#include "forceeffect.h"
#include "player.h"
#include <iostream.h>

using namespace std;

void ForceEffect::notify(const Event currEvent, const Move currMove) {
	if (currEvent == onTurnStart || currEvent == onSAapplied) {
		cout << "newBlock: " << newBlock <<endl;
		player->changeCurrentBlock(newBlock);
		kill();
	}
}
