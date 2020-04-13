#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include "block.h"

class Level {
	bool customSeed;
	int seed;
	int identifier;
	std::ifstream *file;
	const int playerSide;
	
	// abstract ctor
	Level(bool customSeed = 0; int seed = 1, int identifier = 0, std::fstream *file = NULL, const int playerSide) : customSeed{customSeed}, seed{seed}, identifier{identifier}, file{file}, playerSide{playerSide} {}
	Level(Level &&other) : customSeed{other.customSeed}, seed{other.seed}, identifier{other.identifier}, file{other.file}, playerSide{other.playerSide} {}

	public:
	virtual ~Level();

	// getters/setters
	int getIdentifier() const;
	void updateSeed(const int newSeed);

	virtual Block *CreateBlock() = 0;
};

#endif
