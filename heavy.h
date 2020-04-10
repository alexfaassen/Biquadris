#ifndef HEAVY_H
#define HEAVY_H
#include "command.h"

class Heavy : public Command {
	public:
	Heavy() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
