#ifndef LVLD_H
#define LVLD_H
#include "command.h"

class LevelDown : public Command {
	public:
	LevelDown() : {}
	void run(Player *player, const int times) const override;
};

#endif
