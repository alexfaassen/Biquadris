#ifndef LEVEL0_H
#define LEVEL0_H
#include <fstream>
#include "block.h"

class Level0 : public Level {
	public:
	Level0() : Level(), 

	Block *CreateBlock() override;
};

#endif
