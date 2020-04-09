#ifndef LEFT_H
#define LEFT_H
#include "command.h"

class LeftCmd : public Command {
	public:
	LeftCmd() : {}
	private:
	void run(Player &player, const int times = 1) const override;
};

#endif
