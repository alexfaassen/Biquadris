#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

class Player;

class Observer {
	protected:
	Player *player;
	bool alive;

	public:
	Observer(Player *player = NULL, bool alive = true) : player{player}, alive{alive} {}

	bool isAlive() const;
  
	void attach(Player* const newPlayer);

	void kill();

	virtual void notify(const Event currEvent, const int linesCleared) = 0;
	virtual void notify(const Event currEvent, std::vector<std::vector<char>> &boardPrint) = 0;
};

#endif
