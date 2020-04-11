#ifndef LEVEL0_H
#define LEVEL0_H
#include <fstream>
#include "block.h"

class Level0 : public Level {
	public:
	Level0(int seed = 0, int identifier = 0, fstream *file = NULL) : Level(seed, identifier, file) {}

	Block *CreateBlock() override;
};

#endif
