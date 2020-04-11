#ifndef NORAND_H
#define NORAND_H
#include "command.h"

class NoRandom : public Command {
	public:
	NoRandom(const std::string name = "norandom", bool needClean = 1) : name{name}, needClean{needClean} {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
