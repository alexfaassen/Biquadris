#include "blindeffect.h"

void BlindEffect::notify(const Event currEvent, char[][] &boardPrint) override {
	if (currEvent != endTurn) {
		bool blindCol = 0;
		for (int c = 0; c < 11; ++c) {
			if (c >= 2 && c < 9) {
				blindCol = 1;
			} else {
				blindCol = 0;
			}
			// Blind board
			for (int r = 0; r < 15; ++r) {
				if (blindCol || (r >= 2 && r < 12)) {
					char[c][r] = '?';
				}
			}
		}
	} else {
		this->kill();
	}
}
