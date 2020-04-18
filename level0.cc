#include "level0.h"
#include <iostream>

Level0::~Level0() { delete file; }

Level0::Level0(const Level &other) : Level(other) { identifier = 0; }

Level0::Level0(const int playerSide, int identifier, bool customSeed, int seed, std::ifstream *file) : Level(playerSide, identifier, customSeed, seed, file) {
	if (playerSide == 1) {
		file = new std::ifstream{"biquadris_sequence2.txt"};
	} else {
		file = new std::ifstream{"biquadris_sequence1.txt"};
	}
}

Block *Level0::CreateBlock() {
	char b;
	file >> b;
	return new Block(b, identifier);
}
