#ifndef HEAVYEFT_H
#define HEAVYEFT_H
#include "effect.h"

class HeavyEffect : public Effect {
	int numDown;

	public:
	HeavyEffect(int numDown = 1, bool temp = true) : Effect(temp), numDown{numDown} {}

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
