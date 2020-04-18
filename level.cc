#include "level.h" 

Level::Level(const int playerSide, int identifier, bool customSeed = 0, int seed = 1, std::ifstream* file = nullptr) 
: playerSide{playerSide}, identifier{identifier}, customSeed{customSeed}, seed {seed}, file{file} {
}

Level::~Level() { delete file; }

void Level::updateSeed(const int newSeed) { seed = newSeed; }

int Level::getIdentifier() const { return identifier; }

bool Level::setFile(std::ifstream *newFile) {
	if (identifier == 0) {
		return false;
	} else if (file) {
		delete file;
	}
	file = newFile;
	return true;
}
