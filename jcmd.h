#ifndef JCMD_H
#define JCMD_H
#include "command.h"

class JCmd : public Command {
	public:
	JCmd(const std::string name = "J", bool needClean = 1) : name{name}, needClean{needClean} {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
