#ifndef DOWN_H
#define DOWN_H
#include "command.h"
#include "gamestate.h"

class DownCmd : public Command {
	public:
	DownCmd(const std::string name = "down", bool needClean = 1) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
