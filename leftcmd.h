#ifndef LEFT_H
#define LEFT_H
#include "command.h"

class LeftCmd : public Command {
	public:
	LeftCmd() : {}
	void run(Player *player, const int times) const override;
};

#endif
