#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"

class Level0 : public Level {
	public:
	Level0(const int playerSide, int identifier = 0, bool customSeed = false, int seed = 1, std::ifstream *file = NULL);
	Level0(const Level &other);
	~Level0();

	void generateBlocks(std::vector<Observer*> &vec) const override {}
	Block *CreateBlock() override;
};

#endif
