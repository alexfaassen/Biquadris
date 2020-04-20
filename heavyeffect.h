#ifndef HEAVYEFT_H
#define HEAVYEFT_H
#include "effect.h"
#include "cmd.h"

class HeavyEffect : public Effect {
	int numDown;
	vector<Cmd> triggerCommands;

	bool isTrigger(const Cmd c) const;

	public:
	HeavyEffect(bool temp = true, int numDown = 1);

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
