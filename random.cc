#include "random.h"
#include <fstream>
using namespace std;

void Random::run(GameState &game, const int times) const override {
	if (game.getActivePlayer().getLevel() == 3 || game.getActivePlayer().getLevel() == 4) game.getActivePlayer().setFileInput(NULL);
}
