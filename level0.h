#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"

class Level0 : public Level {
	public:
	Level0(bool customSeed; int seed, int identifier = 0, std::ifstream *file, const int playerSide);
	Level0(const Level &other);
	~Level0();

	void generateEffects(std::vector<Observer*> &vec) const override {}
	Block *CreateBlock() override;
};

#endif
