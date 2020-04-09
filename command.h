#ifndef CMD_H
#define CMD_H
#include <string>
#include "gamestate.h"

class Command {
	std::string name;
	public:
	std::string getName() const;

	int longestSubstring(const string playerInput) const; // returns length of longest matching substring of name wtih playerinput
	bool hasSubstring(const string playerInput) const; // returns whether playerInput is a substring

	void execute(GameState *game, const int times) const;
	private:
	virtual void run(GameState *game, const int times = 1) const = 0;
};

#endif
