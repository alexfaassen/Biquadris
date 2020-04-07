#ifndef LVLUP_H
#define LVLUP_H
#include "command.h"

class LevelUp : public Command {
	public:
	LevelUp() : {}
	void run(Player *player, const int times) const override;
};

#endif
