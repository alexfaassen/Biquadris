#include "level0.h"

Level0::Level0(bool customSeed, int seed, int identifier, std::ifstream *file, const int playerID) : Level(customSeed, seed, identifier, file, playerID) {
	identifier = 0;
	if (playerID == 1) {
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
