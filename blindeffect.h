#ifndef BLINDEFT_H
#define BLINDEFT_H
#include "effect.h"

class BlindEffect : public Effect {
	public:
	BlindEffect(bool temp = true) : Effect(temp) {}

	void notify(const Event currEvent, std::vector<std::vector<char>> &boardPrint) override;
	void notify(const Event currEvent, PlayerWindow&) override;
	void notify(const Event currEvent, Move) override;
};

#endif
