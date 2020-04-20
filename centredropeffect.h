#ifndef CDEFT_H
#define CDEFT_H
#include "effect.h"

class CentreDropEffect : public Effect {
	int blocksSinceClear;

	public:
	CentreDropEffect(bool temp = true, int blocksSinceClear = 0) : Effect(temp), blocksSinceClear{blocksSinceClear} {}

	void notify(const Event currEvent, const Move currMove) override;
};

#endif
