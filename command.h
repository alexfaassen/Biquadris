#ifndef CMD_H
#define CMD_H
#include <string>

class GameState;

class Command {
	protected:
	std::string name;
	bool needClean;

	Command(const std::string name, const bool needClean = 1) : name{name}, needClean{needClean} {}
	virtual ~Command();

	virtual void run(GameState &game, const int times = 1) const = 0;
	public:

	std::string getName() const;

	bool hasSubstring(const std::string playerInput) const; // returns whether playerInput is a substring of name

	virtual void execute(GameState &game, const int times) const;
};

#endif
