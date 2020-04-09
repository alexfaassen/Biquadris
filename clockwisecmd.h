#ifndef CW_H
#define CW_H
#include "command.h"

class ClockwiseCmd : public Command {
	public:
	ClockwiseCmd() : {}
	private:
	void run(Player &player, const int times = 1) const override;
};

#endif
