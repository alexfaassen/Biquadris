#ifndef HEAVYEFT_H
#define HEAVYEFT_H
#include "effect.h"

class HeavyEffect : public Effect {
	int numDown;
	std::vector<Move> triggerMoves;

	bool isTrigger(const Move m) const;

	public:
	HeavyEffect(bool temp = true, int numDown = 1);

	void notify(const Event currEvent, const int linesCleared) override;
};

#endif
