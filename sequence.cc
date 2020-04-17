#include "sequence.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Sequence::run(Gamestate &game, const int times) const override {
	std::istream &in = game.getStream();
	std::string fileName;
	in >> fileName;	
	std::ifstream &file{new fileName};
	game.pushToStreams(file);
}
