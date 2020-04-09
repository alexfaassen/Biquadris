#ifndef RIGHT_H
#define RIGHT_H
#include "command.h"

class RightCmd : public Command {
	public:
	RightCmd() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
