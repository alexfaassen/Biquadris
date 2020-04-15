#include "level.h" 

void Level::updateSeed(const int newSeed) { seed = newSeed; }

int Level::getIdentifier() const { return identifier; }

void Level::setFile(std::ifstream *newFile) { if (file) delete file; file = newFile; }
