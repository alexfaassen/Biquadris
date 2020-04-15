#ifndef LEVEL0_H
#define LEVEL0_H
#include "level0.h"

class Level0 : public Level {
	public:
	Level0(bool customSeed = 0; int seed = 1, int identifier = 0, std::ifstream *file = NULL, const int playerSide);
	Level0(Level &&other);
	~Level0();

	Block *CreateBlock() override;
};

#endif
