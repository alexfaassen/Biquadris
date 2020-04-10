#ifndef ICMD_H
#define ICMD_H
#include "command.h"

class ICmd : public Command {
	public:
	ICmd() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
