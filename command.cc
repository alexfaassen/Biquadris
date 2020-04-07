#include "command.h"

std::string Command::getName() const { return name; }

int Command::longestSubstring(String playerInput) const {
	for (int i = 0; i < name.size(); --i) {
		if (name.compare(0, i, playerInput)) return i + 1;
	}
}

//test