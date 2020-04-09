#include "norandom.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void NoRandom::run(Player &player, const int times) const override {
	if (player.getLevel() != 3 || player.getLevel() != 4) return 0;
	string s;
	cin >> s;
	ifstream *file{s};
	player.setFileInput(file);
}
