#ifndef CDEFT_H
#define CDEFT_H
#include "effect.h"

class CentreDropEffect : public Effect {
	int blocksSinceClear;

	public:
	CentreDropEffect(Player *player = NULL, bool alive = 1, int blocksSinceClear = 0) : Effect(player, alive), blocksSinceClear{blocksSinceClear} {}

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
