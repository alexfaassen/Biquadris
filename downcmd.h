#ifndef DOWN_H
#define DOWN_H
#include "command.h"

class DownCmd : public Command {
	public:
	DownCmd() : {}
	void run(Player *player, const int times) const override;
};

#endif
