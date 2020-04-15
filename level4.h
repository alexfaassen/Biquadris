#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"

class Level4 : public Level {
	public:
	Level4(bool customSeed, int seed, int identifier = 4, std::ifstream *file, const int playerSide, Effect *heavy, Effect *centreDrop);
	Level4(const Level &other);
	Level4(const Level3 &other);
	~Level4();

	void generateEffects(std::vector<Observer*> &vec) const override;
	Block *CreateBlock() override;
};

#endif
