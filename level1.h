#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"

class Level1 : public Level {
	public:
	Level1(bool customSeed, int seed, std::ifstream *file, const int playerSide, int identifier = 1);
	Level1(const Level &other);
	~Level1();

	void generateEffects(std::vector<Observer*> &vec) const override {}
	Block *CreateBlock() override;
};

#endif
