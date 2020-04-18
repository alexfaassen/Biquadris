#include "norandom.h"
#include <iostream>
#include <fstream>
#include <sstream>

void NoRandom::run(GameState &game, const int times) const override {
	if (game.getActivePlayer().isLevel() == 3 || game.getActivePlayer().isLevel() == 4) {
		std::istream &in = game.getStream();
		std::string s;
		in >> s;
		std::ifstream *newFile = new ifstream{s};
		game.getActivePlayer().setFileInput(newFile);
	}
}
