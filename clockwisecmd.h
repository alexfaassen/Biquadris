#ifndef CW_H
#define CW_H
#include "command.h"

class ClockwiseCmd : public Command {
	public:
	ClockwiseCmd() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
