#ifndef ICMD_H
#define ICMD_H
#include "command.h"

class ICmd : public Command {
	public:
	ICmd(const std::string name = "I", bool needClean) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
