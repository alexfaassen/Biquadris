#ifndef CCW_H
#define CCW_H
#include "command.h"

class CounterClockwiseCmd : public Command {
	public:
	CounterClockwiseCmd() : {}
	void run(Player *player, const int times) const override;
};

#endif
