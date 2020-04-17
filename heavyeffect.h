#ifndef HEAVYEFT_H
#define HEAVYEFT_H
#include "effect.h"

class HeavyEffect : public Effect {
	int numDown;

	public:
	HeavyEffect(Player *player = NULL, bool alive = 1, int numDown = 2) : Effect(player, alive), numDown{numDown} {}

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
