#ifndef BLINDEFT_H
#define BLINDEFT_H
#include "effect.h"

class BlindEffect : public Effect {
	public:
	BlindEffect(Player *player, bool alive = 1) : Observer(player, alive) {}

	void notify(const Event currEvent, char[][] &boardPrint) override;
};

#endif
