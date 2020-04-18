#ifndef EFFECT_H
#define EFFECT_H
#include "observer.h"

class Effect : public Observer {
	public:
	Effect(Player *player = NULL, bool alive = true) : Observer(player, alive) {}
};

#endif
