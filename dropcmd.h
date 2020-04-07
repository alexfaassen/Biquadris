#ifndef DROP_H
#define DROP_H
#include "command.h"

class DropCmd : public Command {
	public:
	DropCmd() : {}
	void run(Player *player, const int times = 1) const override;
};

#endif
