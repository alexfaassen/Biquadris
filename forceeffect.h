#ifndef FORCEEFT_H
#define FORCEEFT_H
#include "effect.h"

class ForceEffect : public Effect {
	Block *newBlock;

	public:
	ForceEffect(Block *newBlock, Player *player = NULL, bool alive = true) : Effect(player, alive), newBlock{newBlock} {}

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
