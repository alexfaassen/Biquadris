#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"

class Level0 : public Level {
	std::ifstream *scriptfile = nullptr;

	public:
	Level0(const int playerSide, std::string sf, int identifer = 0);
	Level0(const Level &other, std::string sf);

	~Level0();

	Block *CreateBlock() override;
};

#endif
