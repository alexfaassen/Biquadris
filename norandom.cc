#include "norandom.h"
#include "gamestate.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void NoRandom::run(GameState &game, const int times) const {
	istream &in = game.getStream();
	string s;
	in >> s;
	ifstream *newFile = new ifstream{s};
	game.getActivePlayer().setFileInput(newFile);
}
