#ifndef BLINDEFT_H
#define BLINDEFT_H
#include "effect.h"

class BlindEffect : public Effect {
	public:
	BlindEffect(Player *player = NULL, bool alive = true) : Effect(player, alive) {}

	void notify(const Event currEvent, std::vector<std::vector<char>> &boardPrint) override;
	void notify(const Event currEvent, int clearedLines) override;
};

#endif
