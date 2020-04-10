#ifndef JCMD_H
#define JCMD_H
#include "command.h"

class JCmd : public Command {
	public:
	JCmd() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
