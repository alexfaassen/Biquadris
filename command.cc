#include "command.h"

std::string Command::getName() const { return name; }

std::bool Command::hasSubstring(String playerInput) const {
	if (name.size() < playerInput.size()) return 0;
	for (int i = 0; i < playerInput.size(); ++i) {
		if (name.compare(0, i, playerInput)) return 1;
	}
}
