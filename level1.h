#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"

class Level1 : public Level {
	public:
	Level1(const int playerSide, bool customSeed = 0, int seed = 1, std::ifstream *file = NULL, int identifier = 1);
	Level1(const Level &other);
	~Level1();

	void generateEffects(std::vector<Observer*> &vec) const override {}
	Block *CreateBlock() override;
};

#endif
