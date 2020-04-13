#ifndef LEVEL0_H
#define LEVEL0_H
#include "level0.h"

class Level0 : public Level {
	public:
	Level0(bool customSeed; int seed, int identifier = 0, std::ifstream *file, const int playerSide);

	Block *CreateBlock() override;
};

#endif
