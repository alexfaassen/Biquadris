#include "sequence.h"
#include "gamestate.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Sequence::run(GameState &game, const int times) const {
	string s;
	game.readFromStream(s);
	game.pushToStreams(s);
}

