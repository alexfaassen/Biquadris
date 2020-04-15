#include "blindeffect.h"

void BlindEffect::notify(const Event currEvent, vector<vector<char>> &boardPrint) override {
	if (currEvent != onTurnEnd) {
		bool blindRow = 0;
		for (int r = 3; r < 18; ++c) {
			if (c >= 5 && c < 15) {
				blindRow = 1;
			} else {
				blindRow = 0;
			}
			// Blind board
			for (int c = 0; c < 11; ++r) {
				if (blindCol || (c >= 2 && r < 9)) {
					try {
						boardPrint.at(r).at(c) = '?';
					} catch (...) {
						break;
					}
				}
			}
		}
	} else {
		this->kill();
	}
}
