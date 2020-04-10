#ifndef OCMD_H
#define OCMD_H
#include "command.h"

class OCmd : public Command {
	public:
	OCmd() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
