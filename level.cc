#include "level.h" 

Level::~Level() {}

int Level::getIdentifier() const { return identifier; }

bool Level::setFile(std::ifstream *newFile) {
	if (identifier == 0) {
		return false;
	}
	file = newFile;
	return true;
}

void Level::generateEffects(std::vector<Observer*> &vec) const {}
