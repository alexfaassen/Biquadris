#ifndef CCW_H
#define CCW_H
#include "command.h"

class CounterClockwiseCmd : public Command {
	public:
	CounterClockwiseCmd(const std::string name = "counterclockwise", bool needClean) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
