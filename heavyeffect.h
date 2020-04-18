#ifndef HEAVYEFT_H
#define HEAVYEFT_H
#include "effect.h"

class HeavyEffect : public Effect {
	int numDown;

	public:
	HeavyEffect(Player *player = NULL, bool alive = true, int numDown = 1) : Effect(player, alive), numDown{numDown} {}

	void notify(const Event currEvent, const int clearedLines) override;
};

#endif
