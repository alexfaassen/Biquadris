#ifndef RAND_H
#define RAND_H
#include "command.h"

class Random : public Command {
	public:
	Random() : {}
	private:
	void run(GameState *game, const int times = 1) const override;
};

#endif
