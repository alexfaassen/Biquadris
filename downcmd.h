#ifndef DOWN_H
#define DOWN_H
#include "command.h"

class DownCmd : public Command {
	public:
	DownCmd() : {}
	private:
	void run(Player &player, const int times = 1) const override;
};

#endif
