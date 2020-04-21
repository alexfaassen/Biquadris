#ifndef RIGHT_H
#define RIGHT_H
#include "command.h"

class RightCmd : public Command {
	public:
	RightCmd(const std::string name = "right", bool needClean = 1) : Command(name, needClean) {}

	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
