#include "norandom.h"
#include <iostream>
#include <fstream>
#include <sstream>

void NoRandom::run(GameState &game, const int times) const override {
	Player &player = game.getActivePlayer();
	if (player.isLevel() == 3 || player.isLevel() == 4) {
		std::istream &in = game.getStream();
		std::string s;
		in >> s;
		std::ifstream *newFile{new s};
		game.getActivePlayer().setFileInput(newFile);
	}
}
