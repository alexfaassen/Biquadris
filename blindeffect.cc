#include "blindeffect.h"
#include "player.h"
#include "playerwindow.h"

using namespace std;

void BlindEffect::notify(const Event currEvent, vector<vector<char>> &boardPrint) {
	//textDisplay stuff
	if (currEvent == beforeTextDisplay) {
		// blind row
		bool blindRow = 0;
		for (int r = 0; r < 18; ++r) {
			if (r >= 5 && r < 15) {
				blindRow = 1;
			} else {
				blindRow = 0;
			}
			// blind columns
			for (int c = 0; c < 11; ++c) {
				if (blindRow || (c >= 2 && c < 9)) {
					try {
						boardPrint.at(r).at(c) = '?';
					} catch (...) {
						break;
					}
				}
			}
		}
	}
}

void BlindEffect::notify(const Event currEvent, PlayerWindow& window){
	//graphicsDisplay stuff
	if(currEvent == beforeTextDisplay){
		//TODO: draw blind effect
	}
}

void BlindEffect::notify(const Event currEvent, const Move currMove) {
	if(currEvent == onDrop){
		update();
		player->redrawBoard();
	}
}
