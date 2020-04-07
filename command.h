#ifndef CMD_H
#define CMD_H
#include <string>
#include "player.h"

class Command {
	std::string name;
	public:
	std::string getName() const;
	bool hasSubstring(String playerInput) const;
	virtual void run(Player *player, const int times) const = 0;
};

#endif
