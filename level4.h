#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"

class Level4 : public Level {
	public:
	Level4(bool customSeed = 0, int seed = 1, int identifier = 4, std::ifstream *file = NULL, const int playerSide, Effect *heavy, Effect *centreDrop);
	Level4(Level &&other);
	~Level4();

	void generateEffects(); //TODO

	Block *CreateBlock() override;
};

#endif
