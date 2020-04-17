#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"

class Level2 : public Level {
	public:
	Level2(const int playerSide, bool customSeed = 0, int seed = 1, std::ifstream *file = NULL, int identifier = 2);
	Level2(const Level &other);
	~Level2();

	void generateEffects(std::vector<Observer*> &vec) const override {}
	Block *CreateBlock() override;
};

#endif
