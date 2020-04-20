#include "heavyeffect.h"
#include "player.h"
#include <iostream>

using namespace std;

void HeavyEffect::notify(const Event currEvent, const int linesCleared) {
	cout << "test: heavyeffect notify() is called" << endl;
	if (currEvent == afterMove) {
		cout << "test: heavyeffect is running, afterMove" << endl;
		cout << "numDown = " << numDown << endl;
		int moved = player->moveBlock(Down, numDown, false);
		if(moved < numDown){
			player->drop(1, false);
			player->endTurn();
		}
	} else if (currEvent == onTurnEnd) {
		update();
	}
}
