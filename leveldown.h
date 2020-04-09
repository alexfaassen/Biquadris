#ifndef LVLD_H
#define LVLD_H
#include "command.h"

class LevelDown : public Command {
	public:
	LevelDown() : {}
	private:
	void run(Player &player, const int times = 1) const override;
};

#endif
