#ifndef ZCMD_H
#define ZCMD_H
#include "command.h"

class ZCmd : public Command {
	public:
	ZCmd(const std::string name = "Z", bool needClean) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
