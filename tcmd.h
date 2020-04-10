#ifndef TCMD_H
#define TCMD_H
#include "command.h"

class TCmd : public Command {
	public:
	TCmd() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
