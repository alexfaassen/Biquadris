#ifndef LVLUP_H
#define LVLUP_H
#include "command.h"

class LevelUp : public Command {
	public:
	LevelUp() : {}
	private:
	void run(Player &player, const int times = 1) const override;
};

#endif
