#include "level0.h"
#include <iostream>

Level0::Level0(bool customSeed, int seed, int identifier, std::ifstream *file, const int playerSide) : Level(customSeed, seed, identifier, file, playerSide) {
	if (playerSide == 1) {
		file{new biquadris_sequence2.txt};
	} else {
		file{new biquadris_sequence1.txt};
	}
}

Block *Level0::CreateBlock() override {	
	char b;
	file >> b;
	return new Block(b);
}
