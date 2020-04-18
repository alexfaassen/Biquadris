#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"

class Level4 : public Level {
	public:
	Level4(const int playerSide, int identifier = 4, bool customSeed = 0, int seed = 1, std::ifstream *file = NULL, Effect *heavy = NULL, Effect *centreDrop = NULL);
	Level4(const Level &other);
	Level4(const Level3 &other);
	~Level4();

	void generateEffects(std::vector<Observer*> &vec) const override;
	Block *CreateBlock() override;
};

#endif
