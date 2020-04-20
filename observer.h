#ifndef OBSERVER_H
#define OBSERVER_H
#include "event.h"
#include "move.h"

#include <vector>

class Player;
class PlayerWindow;

class Observer {
	protected:
	Player *player = NULL;
	bool alive = true;

	// default ctor
	Observer() {}

	public:
	virtual ~Observer();

	// accessors
	bool isAlive() const; 
	void attach(Player* const newPlayer);
	void kill();

	virtual void notify(const Event currEvent, const Move currMove);
	virtual void notify(const Event currEvent, std::vector<std::vector<char>> &boardPrint);
	virtual void notify(const Event currEvent, PlayerWindow&);
};

#endif
