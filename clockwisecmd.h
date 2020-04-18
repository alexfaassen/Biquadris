#ifndef CW_H
#define CW_H
#include "command.h"

class ClockwiseCmd : public Command {
	public:
	ClockwiseCmd(const std::string name = "clockwise", bool needClean = 1) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
