#ifndef CMD_H
#define CMD_H
#include <string>
#include "player.h"

class GameState;

class Command {
	protected:
	std::string name;
	bool needClean;

	Command(const std::string name, const bool needClean = 1) : name{name}, needClean{needClean} {}

	public:
	virtual ~Command();

	//accessor
	std::string getName() const;

	//returns whether playerInput is a substring of name
	bool hasSubstring(const std::string playerInput) const;

	virtual void execute(GameState &game, const int times) const;

	private:
	virtual void run(GameState &game, const int times = 1) const = 0;
};

#endif
