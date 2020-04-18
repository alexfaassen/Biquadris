#include "sequence.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Sequence::run(GameState &game, const int times) const {
	std::istream &in = game.getStream();
	std::string fileName;
	in >> fileName;
	game.pushToStreams(new std::ifstream{fileName});
}
