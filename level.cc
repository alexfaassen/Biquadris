#include "level.h" 

Level::~Level() { if(file) delete file; }

int Level::getIdentifier() const { return identifier; }

bool Level::setFile(std::ifstream *newFile) {
	if (identifier < 3) {
		return false;
	} else if (file) {
		delete file;
	}
	file = newFile;
	return true;
}

void Level::generateEffects(std::vector<Observer*> &vec) const {}
