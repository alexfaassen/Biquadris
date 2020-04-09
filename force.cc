#include "force.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void Force::run(GameState &game, const int times) const override {
	string b;
	cin >> b;
	game.getNAP().pushToObservers(new ForceEffect(new Block(b), game.getActivePlayer().getLevel()));
}
