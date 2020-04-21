#ifndef BLIND_H
#define BLIND_H
#include "sacommand.h"

class Blind : public SACommand {
	public:
	Blind(const std::string name = "blind", bool needClean = 1) : SACommand(name, needClean) {}

	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
