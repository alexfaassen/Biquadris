#include "norandom.h"
#include "gamestate.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void NoRandom::run(GameState &game, const int times) const {
	string s;
	game.readFromStream(s);
	ifstream *newFile = new ifstream{s};
	if(newFile->good()){
		game.getActivePlayer().setFileInput(newFile);
	} else {
		cout << "Error: " << s << " is missing or unreadable" << endl;
	}
}
