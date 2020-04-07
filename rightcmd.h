#ifndef RIGHT_H
#define RIGHT_H
#include "command.h"

class RightCmd : public Command {
	public:
	RightCmd() : {}
	void run(Player *player, const int times) const override;
};

#endif
