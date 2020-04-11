#ifndef FORCEEFT_H
#define FORCEEFT_H
#include "effect.h"

class ForceEffect : public Effect {
	Block *newBlock;
	public:
	ForceEffect(Player *player, bool alive = 1, Block *newBlock) : Observer(player, alive), newBlock{newBlock} {}

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
