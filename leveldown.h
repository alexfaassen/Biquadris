#ifndef LVLD_H
#define LVLD_H
#include "command.h"

class LevelDown : public Command {
	public:
	LevelDown(const std::string name = "leveldown", bool needClean) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
