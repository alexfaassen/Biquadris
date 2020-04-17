#ifndef OBSERVER_H
#define OBSERVER_H
#include "player.h"

class Observer {
	Player *player;
	bool alive;

	public:
	Observer(Player *player = NULL, bool alive = 1) : player{player}, alive{alive} {}

	bool isAlive() const;
	void attach(Player const *newPlayer);

	void kill();

	virtual void notify(const Event currEvent, const int linesCleared) = 0;
	virtual void notify(const Event currEvent, vector<vector<char>> &boardPrint) = 0;
};

#endif
