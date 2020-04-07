#include "leftcmd.h"

void LeftCmd::run(Player *player, const int times) const override { player->moveBlock(Left, times, 1); }
