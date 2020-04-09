#ifndef RIGHT_H
#define RIGHT_H
#include "command.h"

class RightCmd : public Command {
	public:
	RightCmd() : {}
	private:
	void run(Player &player, const int times = 1) const override;
};

#endif
