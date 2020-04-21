#ifndef FORCE_H
#define FORCE_H
#include "sacommand.h"

class Force : public SACommand {
	public:
	Force(const std::string name = "force", bool needClean = 1) : SACommand(name, needClean) {}

	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
