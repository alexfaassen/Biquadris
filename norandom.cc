#include "norandom.h"
#include "gamestate.h"

#include <iostream>
#include <sstream>
#include <fstream>

void NoRandom::run(GameState &game, const int times) const {
	if (game.getActivePlayer().isLevel() == 3 || game.getActivePlayer().isLevel() == 4) {
		std::istream &in = game.getStream();
		std::string s;
		in >> s;
		std::ifstream *newFile = new std::ifstream{s};
		game.getActivePlayer().setFileInput(newFile);
	}
}
