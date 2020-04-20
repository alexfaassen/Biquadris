#ifndef HEAVYEFT_H
#define HEAVYEFT_H
#include "effect.h"

class HeavyEffect : public Effect {
	int numDown;

	public:
	HeavyEffect(int numDown = 1, bool temp = true) : numDown{numDown}, Effect(temp) {}

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
