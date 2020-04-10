#ifndef HEAVYEFT_H
#define HEAVYEFT_H
#include "effect.h"

class HeavyEffect : public Effect {
	int down;
	public:
	HeavyEffect(int down = 2) : down{down} {}

	notify(const enum Event, const int linesCleared) override;
};

#endif
