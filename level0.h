#ifndef LEVEL0_H
#define LEVEL0_H
#include "level0.h"

class Level0 : public Level {
	public:
	Level0(const int playerSide, bool customSeed = 0, int seed = 1, std::ifstream *file = NULL, int identifier = 0);
	Level0(const Level &other);
	~Level0();

	void generateEffects(std::vector<Observer*> &vec) const override {}
	Block *CreateBlock() override;
};

#endif
