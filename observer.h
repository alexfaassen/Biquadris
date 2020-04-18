#ifndef OBSERVER_H
#define OBSERVER_H
#include "event.h"

#include <vector>

class Player;

class Observer {
	protected:
	Player *player = NULL;
	bool alive = 1;
	
	virtual ~Observer();

	public:
	Observer() {}

	bool isAlive() const;
  
	void attach(Player* const newPlayer);

	void kill();

	virtual void notify(const Event currEvent, const int linesCleared);
	virtual void notify(const Event currEvent, std::vector<std::vector<char>> &boardPrint);
};

#endif
