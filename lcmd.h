#ifndef LCMD_H
#define LCMD_H
#include "command.h"

class LCmd : public Command {
	public:
	LCmd(const std::string name = "L", bool needClean = 1) : Command(name, needClean) {}

	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif

