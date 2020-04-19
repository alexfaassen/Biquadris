#ifndef EFFECT_H
#define EFFECT_H
#include "observer.h"

class Effect : public Observer {
	protected:
	bool temp;
	int duration;
	int currentDur = 0;

	Effect(bool temp = true, int duration = 1) : Observer(), temp{temp}, duration{duration} {}

	void update();
};

#endif
