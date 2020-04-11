#ifndef LEFT_H
#define LEFT_H
#include "command.h"

class LeftCmd : public Command {
	public:
	LeftCmd(const std::string name = "left", bool needClean = 1) : name{name}, needClean{needClean} {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
