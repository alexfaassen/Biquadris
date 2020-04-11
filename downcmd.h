#ifndef DOWN_H
#define DOWN_H
#include "command.h"

class DownCmd : public Command {
	public:
	DownCmd(const std::string name = "down", bool needClean) : name{name}, needClean{needClean} {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
