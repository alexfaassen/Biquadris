#include "norandom.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void NoRandom::run(GameState &game, const int times) const override {
	if (player.getLevel() == 3 || player.getLevel() == 4) {
		string s;
		cin >> s;
		ifstream *file{s};
		game.getActivePlayer().setFileInput(file);
	}
}
