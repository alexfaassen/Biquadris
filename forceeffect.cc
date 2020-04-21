#include "forceeffect.h"
#include "player.h"
#include <ostream.h>

using namespace std;

void ForceEffect::notify(const Event currEvent, const Move currMove) {
	if (currEvent == onTurnStart || currEvent == onSAapplied) {
		cout << "newBlock: " << newBlock <<endl;
		player->changeCurrentBlock(newBlock);
		kill();
	}
}
