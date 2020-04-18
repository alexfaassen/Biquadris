#include "level.h" 

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
