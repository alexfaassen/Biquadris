#ifndef RESTART_H
#define RESTART_H
#include "command.h"

class Restart : public Command {
	public:
	Restart(const std::string name = "restart", bool needClean = 0) : Command(name, needClean) {}
	private:
	void run(GameState *game, const int times = 1) const override;
};

#endif
