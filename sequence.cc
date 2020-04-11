#include "sequence.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Sequence::run(Gamestate &game, const int times) const override {
	istream &in = game.getStream();
	string fileName;
	in >> fileName;	
	ifstream &file{new fileName};
	game.pushToStreams(file);
}
