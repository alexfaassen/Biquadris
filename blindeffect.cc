#include "blindeffect.h"

using namespace std;

void BlindEffect::notify(const Event currEvent, vector<vector<char>> &boardPrint) {
	if (currEvent == beforeTextDisplay) {
		bool blindRow = 0;
		for (int r = 3; r < 18; ++r) {
			if (r >= 5 && r < 15) {
				blindRow = 1;
			} else {
				blindRow = 0;
			}
			// Blind board
			for (int c = 0; c < 11; ++c) {
				if (blindRow || (c >= 2 && r < 9)) {
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

void BlindEffect::notify(const Event currEvent, int clearedLines) {
	if(currEvent == onTurnEnd){
		kill();
	}
}
