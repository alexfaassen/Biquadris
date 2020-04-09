#ifndef NORAND_H
#define NORAND_H
#include "command.h"

class NoRandom : public Command {
	public:
	NoRandom() : {}
	private:
	void run(Player &player, const int times = 1) const override;
};

#endif
