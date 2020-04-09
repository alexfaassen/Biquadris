#include "norandom.h"
#include <fstream>
using namespace std;

void NoRandom::run(Player &player, const int times) const override {
	if (player.getLevel() != 3 || player.getLevel() != 4) return 0;	
	player.setFileInput(NULL);
}
