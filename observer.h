#ifndef OBSERVER_H
#define OBSERVER_H
#include "player.h"

class Observer {
	Player *player;
	bool alive;

	public:
	Observer(Player *player, bool alive = 1) : player{player}, alive{alive} {}

	bool isAlive() const;

	void kill();

	virtual void notify(const Event currEvent, const int clearedLines) = 0;
	virtual void notify(const Event currEvent, char[][] &boardPrint) = 0;
};

#endif
