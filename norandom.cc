#include "norandom.h"
#include <iostream>
#include <fstream>
#include <sstream>

void NoRandom::run(GameState &game, const int times) const override {
	if (player.getLevel() == 3 || player.getLevel() == 4) {
		std::istream &in = game.getStream();
		std::string s;
		in >> s;
		std::ifstream *file{new s};
		game.getActivePlayer().setFileInput(file);
	}
}
