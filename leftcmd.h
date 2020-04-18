#ifndef LEFT_H
#define LEFT_H
#include "command.h"
#include "gamestate.h"

class LeftCmd : public Command {
	public:
	LeftCmd(const std::string name = "left", bool needClean = 1) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
