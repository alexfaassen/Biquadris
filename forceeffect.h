#ifndef FORCEEFT_H
#define FORCEEFT_H
#include "effect.h"
#include <stdio.h>

class ForceEffect : public Effect {
	char newBlock;

	public:
	ForceEffect(const char newBlock) : Effect(), newBlock{newBlock} {}

	void notify(const Event currEvent, const Move currMove) override;
};

#endif
