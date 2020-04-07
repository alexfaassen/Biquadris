#include "leveldown.h"

void LevelDown::run(Player *player, const int times) const override { player->changeLevel(-1 * times); }
