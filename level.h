#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include "block.h"

class Level {
	int seed;
	int identifier;
	std::ifstream *file;
	const int playerID;
	public:
	Level(int seed = 1, int identifier = 0, std::fstream *file = NULL, const int playerID) : seed{seed}, identifier{identifier}, file{file}, playerID{playerID} {}

	// getters/setters
	int getIdentifier() const;
	void updateSeed(const int newSeed);

	virtual Block *CreateBlock() = 0;
};

#endif
