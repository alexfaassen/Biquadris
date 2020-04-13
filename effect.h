#ifndef EFFECT_H
#define EFFECT_H
#include "observer.h"

class Effect : public Observer {
	// private
	Effect(Player *player, bool alive) : Observer(player, alive) {}
};

#endif
