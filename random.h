#ifndef RAND_H
#define RAND_H
#include "command.h"

class Random : public Command {
	public:
	Random(const std::string name = "random", bool needClean = 1) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
