#ifndef CW_H
#define CW_H
#include "command.h"

class ClockwiseCmd : public Command {
	public:
	ClockwiseCmd() : {}
	void run(Player *player, const int times) const override;
};

#endif
