#ifndef TCMD_H
#define TCMD_H
#include "command.h"

class TCmd : public Command {
	public:
	TCmd(const std::string name = "T", bool needClean = 1) : Command(name, needClean) {}

	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif

