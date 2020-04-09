#include "command.h"

std::string Command::getName() const { return name; }

bool Command::hasSubstring(const string playerInput) const { return playerInput == name.substr(0, playerInput.size()); }

int Command::longestSubstring(const string playerInput) const {
	for (int i = 0; i < name.size(); --i) {
		if (name.compare(0, i, playerInput)) return i + 1;
	}
}

void Command::execute(GameState *game, const int times) const {	
	run(game, times);
	game->cleanup();
}

//test
