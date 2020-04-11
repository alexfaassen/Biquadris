#include "force.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void Force::run(GameState &game, const int times) const override {
	istream &in = game.getStream();
	string b;
	in >> b;
	game.getNAP().pushToObservers(new ForceEffect(new Block(b), game.getActivePlayer().getLevel()));
}
