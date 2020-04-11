#ifndef HEAVY_H
#define HEAVY_H
#include "command.h"

class Heavy : public Command {
	public:
	Heavy(const std::string name = "heavy", bool needClean = 1) : name{name}, needClean{needClean} {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
