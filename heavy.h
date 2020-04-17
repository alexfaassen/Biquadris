#ifndef HEAVY_H
#define HEAVY_H
#include "sacommand.h"

class Heavy : public SACommand {
	public:
	Heavy(const std::string name = "heavy", bool needClean = 1) : Command(name, needClean) {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
