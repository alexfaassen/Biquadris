#ifndef BLINDEFT_H
#define BLINDEFT_H
#include "effect.h"

class BlindEffect : public Effect {
	public:
	BlindEffect(Player *player = NULL, bool alive = 1) : Effect(player, alive) {}

	void notify(const Event currEvent, std::vector<std::vector<char>> &boardPrint) override;
};

#endif
