#include "sequence.h"
#include "gamestate.h"

#include <iostream>
#include <fstream>
#include <sstream>

void Sequence::run(GameState &game, const int times) const {
	std::istream &in = game.getStream();
	std::string s;
	in >> s;
	game.pushToStreams(s);
}
