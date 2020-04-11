#ifndef FORCE_H
#define FORCE_H
#include "command.h"

class Force : public Command {
	public:
	Force(const std::string name = "force", bool needClean = 1) : name{name}, needClean{needClean} {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
