#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"

class Level2 : public Level {
	public:
	Level2(const int playerSide, int identifier = 2, bool customSeed = 0, int seed = 1, std::ifstream *file = NULL);
	Level2(const Level &other);
	~Level2();

	Block *CreateBlock() override;
};

#endif
