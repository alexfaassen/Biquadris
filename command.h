#ifndef CMD_H
#define CMD_H
#include <string>
#include "gamestate.h"

class Command {
	std::string name;
	public:
	std::string getName() const;
	int longestSubstring(const string playerInput) const;
	bool hasSubstring(const string playerInput) const;
	void execute(GameState *game, const int times) const;
	private:
	virtual void run(Player &player, const int times = 1) const = 0;
};

#endif
