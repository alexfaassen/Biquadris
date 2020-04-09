#ifndef BLIND_H
#define BLIND_H
#include "command.h"

class Blind : public Command {
	public:
	Blind() : {}
	private:
	void run(GameState &game, const int times = 1) const override;
};

#endif
