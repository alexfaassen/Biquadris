#include "random.h"
#include <fstream>
using namespace std;

void Random::run(GameState *game, const int times) const override {
	if (player.getLevel() == 3 || player.getLevel() == 4) game->getActivePlayer().setFileInput(NULL);
}
