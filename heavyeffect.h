#ifndef HEAVYEFT_H
#define HEAVYEFT_H
#include "effect.h"

class HeavyEffect : public Effect {
	int numDown;

	public:
	HeavyEffect(int numDown = 1) : Effect(), numDown{numDown} {}

	void notify(const Event currEvent, const int clearedLines) override;
};

#endif
