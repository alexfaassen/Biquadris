#ifndef SACOMMAND_H
#define SACOMMAND_H
#include "command.h"

class SACommand : public Command {
	SACommand(const std::string name, const bool needClean = 1) : Command(name, needClean) {}

	public:
	void execute(GameState &game, const int times) const;
};

#endif
