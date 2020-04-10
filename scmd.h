#ifndef SCMD_H
#define SCMD_H
#include "command.h"

class SCmd : public Command {
	public:
	SCmd() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
