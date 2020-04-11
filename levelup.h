#ifndef LVLUP_H
#define LVLUP_H
#include "command.h"

class LevelUp : public Command {
	public:
	LevelUp(const std::string name = "levelup", bool needClean = 1) : name{name}, needClean{needClean} {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
