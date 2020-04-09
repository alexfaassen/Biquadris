#ifndef CCW_H
#define CCW_H
#include "command.h"

class CounterClockwiseCmd : public Command {
	public:
	CounterClockwiseCmd() : {}
	private:
	void run(Player &player, const int times = 1) const override;
};

#endif
