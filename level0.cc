#include "level0.h"
#include <iostream>

Level0::~Level0() { delete file; }

Level0::Level0(const Level &other) : Level(other) {}

Level0::Level0(bool customSeed, int seed, std::ifstream *file, const int playerSide, int identifier) : Level(playerSide, identifier, customSeed, seed, file) {
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
