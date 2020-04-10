#ifndef ZCMD_H
#define ZCMD_H
#include "command.h"

class ZCmd : public Command {
	public:
	ZCmd() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
