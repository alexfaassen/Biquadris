#include "rightcmd.h"

void RightCmd::run(Player *player, const int times) const override { player->moveBlock(Right, times, 1); }
