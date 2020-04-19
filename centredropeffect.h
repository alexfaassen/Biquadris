#ifndef CDEFT_H
#define CDEFT_H
#include "effect.h"

class CentreDropEffect : public Effect {
	int blocksSinceClear;

	public:
	CentreDropEffect(int blocksSinceClear = 0, bool temp = true) : Effect(temp), blocksSinceClear{blocksSinceClear} {}

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
