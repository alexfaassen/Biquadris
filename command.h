#ifndef CMD_H
#define CMD_H
#include <string>

class GameState;

class Command {
	std::string name;
	bool needClean;

	public:
	Command(const std::string name, const bool needClean = 1) : name{name}, needClean{needClean} {}
	virtual ~Command();

	std::string getName() const;

	bool hasSubstring(const std::string playerInput) const; // returns whether playerInput is a substring of name

	virtual void execute(GameState &game, const int times) const;
	private:
	virtual void run(GameState &game, const int times = 1) const = 0;
};

#endif
