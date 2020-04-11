#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include "block.h"

class Level {
	int seed;
	int identifier;
	fstream *file;
	public:
	Level(int seed = 0, int identifier = 0, fstream *file = NULL) : seed{seed}, identifier{identifier}, file{file} {}

	void updateSeed(const int newSeed);

	virtual Block *CreateBlock() = 0;
};

#endif
