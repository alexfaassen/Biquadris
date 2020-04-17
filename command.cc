#include "command.h"

std::string Command::getName() const { return name; }

bool Command::hasSubstring(const std::string playerInput) const { return playerInput == name.substr(0, playerInput.size()); }

void Command::execute(GameState &game, const int times) const {	
	run(game, times);
	if (needClean) game.cleanup();
}
