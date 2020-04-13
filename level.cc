#include "level.h" 

Level::Level(Level &&other) : customSeed{other.customSeed}, seed{other.seed}, identifier{other.identifier}, file{other.file}, playerSide{other.playerSide} {} 

void Level::updateSeed(const int newSeed) { seed = newSeed; }

int Level::getIdentifier() const { return identifier; }
