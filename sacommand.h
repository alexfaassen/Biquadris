#ifndef SACOMMAND_H
#define SACOMMAND_H
#include "command.h"

class SACommand : public Command {
	std::string name;
	bool needClean;

	public:
	SACommand(const std::string name, const bool needClean = 1) : Command(name, needClean) {}

	std::string getName() const;

	bool hasSubstring(const std::string playerInput) const; // returns whether playerInput is a substring of name

	void execute(GameState &game, const int times) const;
};

#endif
