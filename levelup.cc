#include "levelup.h"

void LevelUp::run(Player *player, const int times) const override { player->changeLevel(times); }
