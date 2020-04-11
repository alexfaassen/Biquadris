#include "norandom.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void NoRandom::run(GameState &game, const int times) const override {
	if (player.getLevel() == 3 || player.getLevel() == 4) {
		istream &in = game.getStream();
		string s;
		in >> s;
		ifstream *file{new s};
		game.getActivePlayer().setFileInput(file);
	}
}
