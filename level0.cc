#include "level0.h"
#include <iostream>

using namespace std;

Level0::Level0(const Level &other) : Level(other) { identifier = 0; }

Level0::Level0(const int playerSide, int identifier) : Level(playerSide, identifier) {
	if (playerSide == 1) {
		file = new std::ifstream{"biquadris_sequence2.txt"};
	} else {
		file = new std::ifstream{"biquadris_sequence1.txt"};
	}
}

Block *Level0::CreateBlock() {
	cout << "test: level0 calling CreateBlock()" << endl;
	char b;
	*file >> b >> b;
	return new Block(b, identifier);
}
